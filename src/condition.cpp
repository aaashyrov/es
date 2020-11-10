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

bool Conjunction::is_true(const std::vector<Variable> &facts) {
  for (auto &var:vars_) {
    if (var.is_unknown()) {
      var.get();
    }

    for (const auto &fact:facts) {
      if (var.name() != fact.name()) {
        continue;
      }
      if (var.value() != fact.value()) {
        return false;
      }
    }
  }
  return true;
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

std::vector<Conjunction> &Condition::conjunctions() {
  return conjunctions_;
}
