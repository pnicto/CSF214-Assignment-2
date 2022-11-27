/*!
 * @file stack.cpp
 * @brief Source file for stack
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/stack.h"

/*!
 * @brief Resizes the stack array dynamically
 *@details Assigns Stack::stackElements to Stack::tempStackElements and copies
 *the elements in Stack::stackElements to Stack::tempStackElements while
 *allocating new array with twice the size of old array to Stack::stackElements
 */
void Stack::resizeArray() {
  tempStackElements = stackElements;
  stackElements = new char[maxElements * 2]{};
  for (long long int i = 0; i < maxElements; i++) {
    stackElements[i] = tempStackElements[i];
  }
  maxElements = 2 * maxElements;
  delete[] tempStackElements;
}

/*!
 * @brief Construct a new Stack object
 *@details A new instance of Stack will be created with Stack::stackElements
 *being a char[1], Stack::idx being -1 and Stack::maxElements being 1
 */
Stack::Stack() {
  stackElements = new char[1]{};
  maxElements = 1;
  idx = -1;
}

/*!
 * @brief Destroy the Stack object
 *@details Destroys the allocated Stack::stackElements
 */
Stack::~Stack() { delete[] stackElements; }

/*!
 * @brief Adds the element to the stack
 *
 * @param element
 */
void Stack::push(char element) {
  if (idx >= maxElements - 1) {
    resizeArray();
  }
  idx++;
  stackElements[idx] = element;
};

/*!
 * @brief Removes the element at the top of the stack and returns it
 *
 * @return char
 */
char Stack::pop() {
  if (idx >= 0) {
    char elementToBeReturned = stackElements[idx];
    stackElements[idx] = 0;
    idx--;
    return elementToBeReturned;
  }
  return 0;
}

/*!
 * @brief Prints the elements of the stack in bottom to top manner
 *
 */
void Stack::printStack() {
  for (long long int i = 0; i < maxElements; i++) {
    std::cout << stackElements[i] << std::endl;
  }
}
