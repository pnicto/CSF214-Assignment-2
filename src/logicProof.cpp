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
