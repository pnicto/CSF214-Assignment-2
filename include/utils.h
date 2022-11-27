#pragma once

#include <algorithm>

#include "stack.h"

std::string infixToPrefix(std::string infixFormula);
std::string prefixToInfix(std::string prefixFormula, bool returnLeft = true);
std::string* getSubformulas(std::string infixFormula);