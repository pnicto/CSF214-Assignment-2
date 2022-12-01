/**
 * @file proofLine.h
 * @brief Header file for proofLine.cpp
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <string>

/**
 * @brief Class for proof line
 * @details Object representation of a line in a proof
 *
 */
class ProofLine {
 private:
  /**
   * @brief Formula, which is the result of applying a specific rule in the
   * previous step
   *
   */
  std::string formula;
  /**
   * @brief The rule that is applied on the given formula
   *
   */
  std::string rule;
  /**
   * @brief Reference to a line in the logic proof (1)
   *
   */
  int lineReference1;
  /**
   * @brief Reference to a line in the logic proof (2)
   *
   */
  int lineReference2;

 public:
  ProofLine(const std::string& str);

  const std::string getFormula() const;
  const std::string getRule() const;
  int getLineReference1() const;
  int getLineReference2() const;
};