//
// Created by alisher on 11/9/20.
//

#include <rule.hpp>

Rule::Rule() {
  condition_.clear();
}

Rule::Rule(const Condition &condition, const Variable &conclusion) : condition_(condition), conclusion_(conclusion) {}

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

bool Rule::copyFrom(const rapidjson::Value &jVal) {
  if (not jVal.IsObject()) {
    std::cerr << "json is not object" << std::endl;
    return false;
  }
  if (not jVal.HasMember("if")) {
    std::cerr << "object has no if" << std::endl;
    return false;
  }
  if (not jVal["if"].IsArray()) {
    std::cerr << "if is not an array" << std::endl;
    return false;
  }

  for (const auto &jIfVal:jVal["if"].GetArray()) {
    if (not jIfVal.IsArray()) {
      std::cerr << "if section is not array" << std::endl;
      return false;
    }

    Conjunction conjunction;
    for (const auto &jVar:jIfVal.GetArray()) {
      Variable var;
      if (not var.copyFrom(jVar)) {
        std::cerr << "can not copy variable from object" << std::endl;
        return false;
      }
      conjunction.push(var);
    }

    condition_.push(conjunction);
  }

  return true;
}

std::ostream &operator<<(std::ostream &os, const Rule &rule) {

  return os;
}
