//
// Created by alisher on 11/9/20.
//

#include <rule.hpp>

Rule::Rule(const Condition &condition, const Variable &conclusion) : condition_(condition), conclusion_(conclusion) {}

bool Rule::is_simple() {

  return false;
}

bool Rule::is_true(const std::vector<Variable> &known_vars) {
  for (auto &conj:condition_.conjunctions()) {
    if (conj.is_true(known_vars)) {
      return true;
    }
  }
  return false;
}

const Variable &Rule::conclusion() {
  return conclusion_;
}

