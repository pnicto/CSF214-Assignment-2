/**
 * @file logicProof.h
 * @brief Header file for logicProof.cpp
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <stdexcept>

#include "proofLine.h"
#include "utils.h"

/**
 * @brief Class for logic proof
 * @details Object representation of a logic proof
 *
 */
class LogicProof {
 private:
  /**
   * @brief Number of lines in the proof
   *
   */
  int length;

  /**
   * @brief Attribute containing the proof lines
   *
   */
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
