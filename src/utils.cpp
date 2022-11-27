#include "../include/utils.h"

/*!
 * @brief Takes the infix formula given and converts into prefix formula
 * @param infixFormula
 * @details Reverses the given infix formula and iterates through the formula
 * pushing "+" , "*", ">", "~", ")" into the stack while the
 * remaining characters are added to prefix string variable until "(" is found.
 * Then the stack is popped until ")" again adding the popped operators to the
 * prefix string.
 *char
 * @return std::string prefixFormula
 */
std::string infixToPrefix(std::string infixFormula) {
  // Create operator stack
  Stack operatorStack{};
  // Create empty prefix formula
  std::string prefixFormula{};

  // Reverse the formula as per the algorithm
  std::reverse(infixFormula.begin(), infixFormula.end());

  // Iterate through the string and add the operators to stack
  for (char character : infixFormula) {
    std::string characterString{character};
    switch (character) {
      case '~':
      case '+':
      case '*':
      case '>':
      case ')':
        operatorStack.push(characterString);
        break;

        // When '(' is the character in the reversed infix formula, start
        // popping the stack and add to the prefix formula until ')' else* add
        // the character to operator stack

      case '(':
        while (1) {
          std::string operatorToBeAdded = operatorStack.pop();
          if (operatorToBeAdded[0] == ')')
            break;
          else
            prefixFormula += operatorToBeAdded;
        }
        break;

        // If the character is not an operator append it to the prefix
      default:
        prefixFormula += character;
        break;
    }
  }

  // Reverse the prefix formula string created so far to get the
  std::reverse(prefixFormula.begin(), prefixFormula.end());

  return prefixFormula;
}