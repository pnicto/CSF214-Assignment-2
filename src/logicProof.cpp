#include "../include/logicProof.h"

LogicProof::LogicProof(int proofLength) {
  length = proofLength;

  linesOfProof = new ProofLine* [length] {};
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
          infixToPrefix(currentLine.getFormula())[0] != '+' || rule[1] != 'i')
        return false;

      if (rule[2] == '1') {
        if (subformulas[0] ==
            this->getFormula(currentLine.getLineReference1())) {
          return true;
        }

        return false;
      }
      if (rule[2] == '2') {
        if (subformulas[1] ==
            this->getFormula(currentLine.getLineReference1())) {
          return true;
        }
      }
      return false;
      break;
    }

    case '*': {
      if (rule[1] == 'i') {
        std::string* subformulas = getSubformulas(currentLine.getFormula());

        if (lineNo <= currentLine.getLineReference1() ||
            lineNo <= currentLine.getLineReference2() ||
            infixToPrefix(currentLine.getFormula())[0] != '*') {
          return false;
        }

        if (subformulas[0] ==
                this->getFormula(currentLine.getLineReference1()) &&
            subformulas[1] ==
                this->getFormula(currentLine.getLineReference2())) {
          return true;
        }

        return false;
      }

      if (rule[1] == 'e') {
        std::string* referenceSubformulas =
            getSubformulas(this->getFormula(currentLine.getLineReference1()));

        if (lineNo <= currentLine.getLineReference1() ||
            infixToPrefix(
                this->getFormula(currentLine.getLineReference1()))[0] != '*') {
          return false;
        }

        if (rule[2] == '1') {
          if (referenceSubformulas[0] == currentLine.getFormula()) {
            return true;
          }
          return false;
        }

        if (rule[2] == '2') {
          if (referenceSubformulas[1] == currentLine.getFormula()) {
            return true;
          }
          return false;
        }
      }

      return false;
    }

      }

      return false;
    }
    default:
      return false;
  }
}