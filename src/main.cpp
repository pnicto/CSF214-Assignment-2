#include "../include/main.h"

int main() {
  int proofLength{};
  std::cout
      << "Enter the number of lines, followed by each line of the proof:\n";
  std::cin >> proofLength;

  std::string* linesOfProof = (new std::string[proofLength]{});
  for (int i = 0; i < proofLength; i++) {
    std::getline(std::cin, (linesOfProof[i]));
  }

  return 0;
}