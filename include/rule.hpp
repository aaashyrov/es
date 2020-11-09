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
 private:
  Condition condition_;
  Variable conclusion_;
};

#endif //ES_INCLUDE_RULE_HPP_
