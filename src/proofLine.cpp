#include "../include/proofLine.h"

ProofLine::ProofLine(const std::string& str) {
  int delim1Index{0};
  int delim2Index{0};
  int delim3Index{0};

  for (unsigned int i{0}; i < str.length(); i++) {
    if (str[i] == '/') {
      if (!delim1Index) {
        delim1Index = i;
      } else if (!delim2Index) {
        delim2Index = i;
      } else if (!delim3Index) {
        delim3Index = i;
      }
    }
  }
  std::cout << "1 is: " << delim1Index << "\n";
  std::cout << "2 is: " << delim2Index << "\n";
  std::cout << "3 is: " << delim3Index << "\n";

  formula = str.substr(0, delim1Index);

  if (!delim1Index) {
    return;
  }
  if (!delim2Index) {
    rule = str.substr(delim1Index + 1, str.length() - delim1Index - 1);
    lineReference1 = lineReference2 = 0;
  } else {
    rule = str.substr(delim1Index + 1, delim2Index - delim1Index - 1);
    if (!delim3Index) {
      lineReference1 =
          std::stoi(str.substr(delim2Index + 1, str.length() - delim2Index));
      lineReference2 = 0;
    } else {
      lineReference1 =
          std::stoi(str.substr(delim2Index + 1, delim3Index - delim2Index));

      lineReference2 =
          std::stoi(str.substr(delim3Index + 1, str.length() - delim3Index));
    }
  }
}

const std::string ProofLine::getFormula() { return formula; }
const std::string ProofLine::getRule() { return rule; }
int ProofLine::getLineReference1() { return lineReference1; }
int ProofLine::getLineReference2() { return lineReference2; }
