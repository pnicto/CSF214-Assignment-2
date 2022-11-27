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

  for (int i{0}; i < proof.getLength(); i++) {
    std::cout << proof.getFormula(i + 1) << "\n"
              << proof.getRule(i + 1) << "\n"
              << proof.getLineReference1(i + 1) << "\n"
              << proof.getLineReference2(i + 1) << "\n\n";
  }

  return 0;
}