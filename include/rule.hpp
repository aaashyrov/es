//
// Created by alisher on 11/9/20.
//

#ifndef ES_INCLUDE_RULE_HPP_
#define ES_INCLUDE_RULE_HPP_
#include <iostream>
#include <condition.hpp>

class Rule {
 public:
  Rule(const Condition &condition, const Variable &conclusion);
  ~Rule() = default;

  bool is_simple();
  const Variable& conclusion();
  bool is_true(const std::vector<Variable>& known_vars);
 private:
  Condition condition_;
  Variable conclusion_;
};

#endif //ES_INCLUDE_RULE_HPP_
