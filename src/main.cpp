/**
 * @file main.cpp
 * @brief Source file for main.h
 * @details Where all the pieces are connected
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/main.h"

int main() {
  int proofLength{};
  std::cout
      << "Enter the number of lines, followed by each line of the proof:\n";
  std::cin >> proofLength;
  std::cin.ignore();

  LogicProof proof = LogicProof(proofLength);

  for (int i{0}; i < proof.getLength(); i++) {
    std::string temp{};
    std::getline(std::cin, temp);
    proof.setLine(i + 1, temp);
  }

  std::cout << ((proof.isValid()) ? "The proof is valid"
                                  : "The proof is invalid")
            << "\n";

  return 0;
}