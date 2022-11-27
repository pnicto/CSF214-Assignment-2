#pragma once

#include <iostream>
#include <string>

class ProofLine {
 private:
  std::string formula;
  std::string rule;
  int lineReference1;
  int lineReference2;

 public:
  ProofLine(const std::string& str);

  const std::string getFormula();
  const std::string getRule();
  int getLineReference1();
  int getLineReference2();
};