//
// Created by alisher on 11/9/20.
//

#include <variable.hpp>

const unsigned int Value::UNKNOWN = 0;

Variable::Variable(const std::string &name, const std::vector<std::string> &descriptions, size_t value) {
  name_ = name;
  descriptions_ = descriptions;
  value_.id = (value > 0 and descriptions.size() > value) ? value : Value::UNKNOWN;
  value_.description = (value_.id != Value::UNKNOWN) ? descriptions.at(value) : "UNKNOWN";
}

bool Variable::is_unknown() const {
  return value_.id == Value::UNKNOWN;
}

std::ostream &operator<<(std::ostream &os, const Value &value) {
  os << " [" << value.description << "] ";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Variable &value) {
  os << value.name_ << " = " << value.value_;
  return os;
}
