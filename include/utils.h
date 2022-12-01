/**
 * @file utils.h
 * @brief Header file for utils.cpp
 * @date 01-12-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <algorithm>

#include "stack.h"

std::string infixToPrefix(std::string infixFormula);
std::string prefixToInfix(std::string prefixFormula, bool returnLeft = true);
std::string* getSubformulas(std::string infixFormula);
std::string removeNegation(std::string formula);