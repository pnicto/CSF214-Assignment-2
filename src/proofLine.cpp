/**
 * @file proofLine.cpp
 * @brief Source file for proofLine.h
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/proofLine.h"

/**
 * @brief Construct a Proof Line object for the given string
 *
 * @param str
 */
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

/**
 * @brief Gets the formula present in the proof line
 *
 * @return const std::string
 */
const std::string ProofLine::getFormula() const { return formula; }

/**
 * @brief Gets the rule present in the proof line
 *
 * @return const std::string
 */
const std::string ProofLine::getRule() const { return rule; }

/**
 * @brief Gets the line reference (1) referenced while applying the rule
 *
 * @return int
 */
int ProofLine::getLineReference1() const { return lineReference1; }

/**
 * @brief Gets the line reference (2) referenced while applying the rule
 *
 * @return int
 */
int ProofLine::getLineReference2() const { return lineReference2; }
