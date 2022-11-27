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

std::string prefixToInfix(std::string prefixFormula, bool returnLeft) {
  Stack operandStack{};
  std::reverse(prefixFormula.begin(), prefixFormula.end());
  for (char character : prefixFormula) {
    switch (character) {
      case '+':
      case '*':
      case '>': {
        std::string operand1 = operandStack.pop();
        std::string operand2 = operandStack.pop();
        std::string temp = "(" + operand1 + character + operand2 + ")";
        operandStack.push(temp);
        break;
      }
      case '~': {
        std::string operand = operandStack.pop();
        std::string temp = "(" + character + operand + ")";
        operandStack.push(temp);
        break;
      }
      default: {
        std::string temp{character};
        operandStack.push(temp);
      }
    }
  }

  std::string temp1 = operandStack.pop();
  std::string temp2 = operandStack.pop();
  if (temp2 == "\0" || returnLeft) {
    return temp1;
  } else {
    return temp2;
  }
}

std::string* getSubformulas(std::string infixFormula) {
  std::string* subformulas = new std::string[2]{};
  std::string prefixFormula = infixToPrefix(infixFormula);
  prefixFormula = prefixFormula.substr(1, prefixFormula.length() - 1);
  subformulas[0] = prefixToInfix(prefixFormula, true);
  subformulas[1] = prefixToInfix(prefixFormula, false);
  return subformulas;
}