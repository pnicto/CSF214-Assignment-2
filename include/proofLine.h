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

  const std::string getFormula() const;
  const std::string getRule() const;
  int getLineReference1() const;
  int getLineReference2() const;
};