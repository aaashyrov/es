//
// Created by alisher on 11/9/20.
//

#include <condition.hpp>

void Conjunction::pop() {
  if (vars_.empty()) {
    return;
  }
  vars_.erase(vars_.end());
}

void Conjunction::push(const Variable &variable) {
  vars_.push_back(variable);
}

void Conjunction::clear() {
  vars_.clear();
}

void Condition::push(const Conjunction &conjunction) {
  conjunctions_.emplace_back(conjunction);
}

void Condition::pop() {
  conjunctions_.erase(conjunctions_.end());
}

void Condition::clear() {
  conjunctions_.clear();
}
