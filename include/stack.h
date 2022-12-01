/**
 * @file stack.h
 * @brief Header file for stack.cpp
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <string>

/*!
 * @brief Custom stack defined for multiple purposes
 *
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
