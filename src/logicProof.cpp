#include "../include/logicProof.h"

LogicProof::LogicProof(int proofLength) {
  length = proofLength;

  linesOfProof = new ProofLine* [length] {};
}

void LogicProof::setLine(int lineNo, std::string str) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }

  linesOfProof[lineNo - 1] = new ProofLine(str);
}

int LogicProof::getLength() { return length; }

const std::string LogicProof::getFormula(int lineNo) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  return (*(linesOfProof[lineNo - 1])).getFormula();
}

const std::string LogicProof::getRule(int lineNo) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  return (*(linesOfProof[lineNo - 1])).getRule();
}

int LogicProof::getLineReference1(int lineNo) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  return (*(linesOfProof[lineNo - 1])).getLineReference1();
}

int LogicProof::getLineReference2(int lineNo) {
  if (lineNo > length) {
    throw std::invalid_argument("received index greater than proof length");
  }
  return (*(linesOfProof[lineNo - 1])).getLineReference2();
}

bool validateLine(LogicProof& proof, int lineNo) {
  if (lineNo > proof.getLength()) {
    throw std::invalid_argument("received index greater than proof length");
  }
  std::string rule = proof.getRule(lineNo);

  switch (rule[0]) {
    case 'p':
    case 'P':
      return true;
      break;
    case '+': {
      std::string* subformulas = getSubformulas(proof.getFormula(lineNo));

      if (lineNo <= proof.getLineReference1(lineNo) ||
          infixToPrefix(proof.getFormula(lineNo))[0] != '+')
        return false;

      if (rule[2] == '1') {
        if (subformulas[0] ==
            proof.getFormula(proof.getLineReference1(lineNo))) {
          return true;
        }

        return false;
      }

      if (rule[2] == '2') {
        if (subformulas[1] ==
            proof.getFormula(proof.getLineReference1(lineNo))) {
          return true;
        }
      }
      return false;
      break;
    }
    case '*': {
      if (rule[1] == 'i') {
        std::string* subformulas = getSubformulas(proof.getFormula(lineNo));

        if (lineNo <= proof.getLineReference1(lineNo) ||
            lineNo <= proof.getLineReference2(lineNo) ||
            infixToPrefix(proof.getFormula(lineNo))[0] != '*') {
          return false;
        }

        if (subformulas[0] ==
                proof.getFormula(proof.getLineReference1(lineNo)) &&
            subformulas[1] ==
                proof.getFormula(proof.getLineReference2(lineNo))) {
          return true;
        }

        return false;
      }

      if (rule[1] == 'e') {
        std::string* referenceSubformulas =
            getSubformulas(proof.getFormula(proof.getLineReference1(lineNo)));

        if (lineNo <= proof.getLineReference1(lineNo) ||
            infixToPrefix(
                proof.getFormula(proof.getLineReference1(lineNo)))[0] != '*') {
          return false;
        }

        if (rule[2] == '1') {
          if (referenceSubformulas[0] == proof.getFormula(lineNo)) {
            return true;
          }
          return false;
        }

        if (rule[2] == '2') {
          if (referenceSubformulas[1] == proof.getFormula(lineNo)) {
            return true;
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