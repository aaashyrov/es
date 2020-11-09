//
// Created by alisher on 11/9/20.
//

#ifndef ES_INCLUDE_VARIABLE_HPP_
#define ES_INCLUDE_VARIABLE_HPP_
#include <string>
#include <vector>
#include <iostream>

struct Value {
  static const unsigned int UNKNOWN;

  size_t id;
  std::string description;
};

std::ostream &operator<<(std::ostream &os, const Value &value);

class Variable {
 public:

  Variable(const std::string &name, const std::vector<std::string> &descriptions, size_t val = Value::UNKNOWN);
  ~Variable() = default;

  void get();
  bool is_unknown() const;
  const Value &value() const;
  const std::string &name() const;
  bool is_known(const std::vector<Variable>& facts) const;
  friend std::ostream &operator<<(std::ostream &os, const Variable &value);
 protected:

  Value value_;
  std::string name_;
  std::vector<std::string> descriptions_;
};


#endif //ES_INCLUDE_VARIABLE_HPP_
