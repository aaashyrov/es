//
// Created by alisher on 11/9/20.
//

#ifndef ES_INCLUDE_CONDITION_HPP_
#define ES_INCLUDE_CONDITION_HPP_
#include <iostream>

#include <variable.hpp>

class Conjunction {
 public:
  Conjunction() = default;
  ~Conjunction() = default;

  void pop();
  void clear();
  void push(const Variable &variable);

 protected:
  std::vector<Variable> vars_;
};

class Condition {
 public:
  Condition() = default;
  ~Condition() = default;

  void pop();
  void clear();
  void push(const Conjunction &conjunction);

 protected:
  std::vector<Conjunction> conjunctions_;
};

#endif //ES_INCLUDE_CONDITION_HPP_
