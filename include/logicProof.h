#pragma once

#include <iostream>
#include <stdexcept>

#include "proofLine.h"
#include "utils.h"

class LogicProof {
 private:
  int length;
  ProofLine** linesOfProof;

 public:
  LogicProof(int proofLength);

  void setLine(int lineNo, std::string str);

  int getLength();

  const std::string getFormula(int lineNo);

  const std::string getRule(int lineNo);

  int getLineReference1(int lineNo);

  int getLineReference2(int lineNo);

  bool isValid();
};

bool validateLine(LogicProof& proof, int lineNo);