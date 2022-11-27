/*!
 * @file stack.h
 * @brief Header file for stack
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <string>

/*!
 * @brief Class for stack to store operators to convert the propositional logic
 * formula from infix to prefix.
 *
 */
class Stack {
 private:
  /*!
   * @brief Elements of the stack
   *
   */
  std::string* stackElements;

  /*!
   * @brief Temporary variable to store the elements of the stack before
   * resizing the stack
   *
   */
  std::string* tempStackElements;

  /*!
   * @brief Maximum elements the stack can store
   *
   */
  long long int maxElements{};

  /*!
   * @brief Index of the topmost element in the stack
   *
   */
  long long int idx{};

  void resizeArray();

 public:
  Stack();
  ~Stack();

  void push(std::string element);
  std::string pop();

  void printStack();
};
