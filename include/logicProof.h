#pragma once

#include <stdexcept>

#include "proofLine.h"
#include "utils.h"

class LogicProof {
 private:
  int length;
  ProofLine** linesOfProof;

 public:
  LogicProof(int proofLength);
  ~LogicProof();

  void setLine(int lineNo, std::string str);

  int getLength() const;
  const std::string getFormula(int lineNo) const;
  const std::string getRule(int lineNo) const;
  int getLineReference1(int lineNo) const;
  int getLineReference2(int lineNo) const;
  const ProofLine& getProofLine(int lineNo) const;

  bool validateLine(int lineNo);
  bool isValid();
};
