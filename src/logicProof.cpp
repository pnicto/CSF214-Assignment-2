#include "../include/logicProof.h"

LogicProof::LogicProof(int proofLength) {
  length = proofLength;

  linesOfProof = new ProofLine* [length] {};
}

LogicProof::~LogicProof() {
  for (int i{0}; (i < length); i++) {
    delete linesOfProof[i];
  }
  delete[] linesOfProof;
}

void LogicProof::setLine(int lineNo, std::string str) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }

  linesOfProof[lineNo - 1] = new ProofLine(str);
}

int LogicProof::getLength() const { return length; }

const std::string LogicProof::getFormula(int lineNo) const {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  return (*(linesOfProof[lineNo - 1])).getFormula();
}

const std::string LogicProof::getRule(int lineNo) const {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  return (*(linesOfProof[lineNo - 1])).getRule();
}

int LogicProof::getLineReference1(int lineNo) const {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  return (*(linesOfProof[lineNo - 1])).getLineReference1();
}

int LogicProof::getLineReference2(int lineNo) const {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  return (*(linesOfProof[lineNo - 1])).getLineReference2();
}

const ProofLine& LogicProof::getProofLine(int lineNo) const {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  return (*(linesOfProof[lineNo - 1]));
}

bool LogicProof::isValid() {
  bool flag = true;
  for (int i{0}; (i < length) && flag; i++) {
    if (!(validateLine(i + 1))) {
      flag = false;
    }
  }
  return flag;
}

bool LogicProof::validateLine(int lineNo) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  if (lineNo < 1) {
    throw std::invalid_argument("received index less than 1");
  }
  const ProofLine& currentLine = this->getProofLine(lineNo);
  std::string rule = currentLine.getRule();

  switch (rule[0]) {
    case 'p':
    case 'P':
      return true;
      break;

    case '+': {
      std::string* subformulas = getSubformulas(currentLine.getFormula());

      if (lineNo <= currentLine.getLineReference1() ||
          infixToPrefix(currentLine.getFormula())[0] != '+' || rule[1] != 'i') {
        delete[] subformulas;
        return false;
      }

      if (rule[2] == '1') {
        if (subformulas[0] ==
            this->getFormula(currentLine.getLineReference1())) {
          delete[] subformulas;
          return true;
        }
        delete[] subformulas;
        return false;
      }
      if (rule[2] == '2') {
        if (subformulas[1] ==
            this->getFormula(currentLine.getLineReference1())) {
          delete[] subformulas;
          return true;
        }
      }
      delete[] subformulas;
      return false;
      break;
    }

    case '*': {
      if (rule[1] == 'i') {
        std::string* subformulas = getSubformulas(currentLine.getFormula());

        if (lineNo <= currentLine.getLineReference1() ||
            lineNo <= currentLine.getLineReference2() ||
            infixToPrefix(currentLine.getFormula())[0] != '*') {
          delete[] subformulas;
          return false;
        }

        if (subformulas[0] ==
                this->getFormula(currentLine.getLineReference1()) &&
            subformulas[1] ==
                this->getFormula(currentLine.getLineReference2())) {
          delete[] subformulas;
          return true;
        }

        delete[] subformulas;
        return false;
      }

      if (rule[1] == 'e') {
        std::string* referenceSubformulas =
            getSubformulas(this->getFormula(currentLine.getLineReference1()));

        if (lineNo <= currentLine.getLineReference1() ||
            infixToPrefix(
                this->getFormula(currentLine.getLineReference1()))[0] != '*') {
          delete[] referenceSubformulas;
          return false;
        }

        if (rule[2] == '1') {
          if (referenceSubformulas[0] == currentLine.getFormula()) {
            delete[] referenceSubformulas;
            return true;
          }
          delete[] referenceSubformulas;
          return false;
        }

        if (rule[2] == '2') {
          if (referenceSubformulas[1] == currentLine.getFormula()) {
            delete[] referenceSubformulas;
            return true;
          }
          delete[] referenceSubformulas;
          return false;
        }
      }

      return false;
    }

    case '>': {
      if (lineNo <= currentLine.getLineReference1() ||
          lineNo <= currentLine.getLineReference2() || rule[1] != 'e' ||
          infixToPrefix(this->getFormula(currentLine.getLineReference1()))[0] !=
              '>') {
        return false;
      }

      std::string* referenceSubformulas =
          getSubformulas(this->getFormula(currentLine.getLineReference1()));

      if (referenceSubformulas[0] ==
              this->getFormula(currentLine.getLineReference2()) &&
          referenceSubformulas[1] == currentLine.getFormula()) {
        delete[] referenceSubformulas;
        return true;
      }
      delete[] referenceSubformulas;
      return false;
    }

    case 'M':
    case 'm': {
      if (lineNo <= currentLine.getLineReference1() ||
          lineNo <= currentLine.getLineReference2() ||
          (rule[1] != 'T' && rule[1] != 't') ||
          infixToPrefix(this->getFormula(currentLine.getLineReference1()))[0] !=
              '>') {
        return false;
      }

      if (currentLine.getFormula()[1] != '~' ||
          this->getFormula(currentLine.getLineReference2())[1] != '~') {
        return false;
      }

      std::string* referenceSubformulas =
          getSubformulas(this->getFormula(currentLine.getLineReference1()));

      if (removeNegation(currentLine.getFormula()) == referenceSubformulas[0] &&
          removeNegation(this->getFormula(currentLine.getLineReference2())) ==
              referenceSubformulas[1]) {
        delete[] referenceSubformulas;
        return true;
      }

      delete[] referenceSubformulas;
      return false;
    }

    default:
      return false;
  }
}