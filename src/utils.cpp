#include "../include/utils.h"

/*!
 * @brief Takes the infix formula given and converts into prefix formula
 * @param infixFormula
 * @details Reverses the given infix formula and iterates through the formula
 * pushing "+" , "*", ">", "~", ")" into the stack while the
 * remaining characters are added to prefix string variable until "(" is found.
 * Then the stack is popped until ")" again adding the popped operators to the
 * prefix string.
 *
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
    switch (character) {
      case '~':
      case '+':
      case '*':
      case '>':
      case ')':
        operatorStack.push(character);
        break;

        // When '(' is the character in the reversed infix formula, start
        // popping the stack and add to the prefix formula until ')' else* add
        // the character to operator stack

      case '(':
        while (1) {
          char operatorToBeAdded = operatorStack.pop();
          if (operatorToBeAdded == ')')
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