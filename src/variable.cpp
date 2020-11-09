//
// Created by alisher on 11/9/20.
//

#include <variable.hpp>
#include <iostream>
#include <algorithm>

const unsigned int Value::UNKNOWN = 0;
bool is_number(const std::string &s) {
  return all_of(s.cbegin(), s.cend(), [](const char &c) {
    return isdigit(c);
  });
}

Variable::Variable(const std::string &name, const std::vector<std::string> &descriptions, size_t val) {
  name_ = name;
  descriptions_ = descriptions;
  value_.id = (val > 0 and descriptions.size() > val) ? val : Value::UNKNOWN;
  value_.description = (value_.id != Value::UNKNOWN) ? descriptions.at(val) : "UNKNOWN";
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

const Value &Variable::value() const {
  return value_;
}

const std::string &Variable::name() const {
  return name_;
}

void Variable::get() {
  std::string str;
  do {
    std::cout << "enter " << name_ << std::endl;
    std::cout << "available descriptions are: " << std::endl;
    size_t i = 1;
    for (const auto &desc:descriptions_) {
      std::cout << "[" << i << "]: " << desc << std::endl;
    }

    std::cin >> str;
    if (is_number(str)) {
      int x = std::stoi(str);
      if (x <= 0 or x > descriptions_.size() - 1) {
        continue;
      }
      value_.id = x;
      value_.description = descriptions_.at(x);
      return;
    }
  } while (true);
}

bool Variable::is_known(const std::vector<Variable> &facts)const {
  for (const auto &fact:facts) {
    if (fact.name() == name_) {
      return true;
    }
  }
  return false;
}



