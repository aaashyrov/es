//
// Created by alisher on 11/9/20.
//
#include <memory>
#include <algorithm.hpp>

std::shared_ptr<std::vector<Variable>> get_known_vars(const std::vector<Variable> &vars) {
  std::shared_ptr<std::vector<Variable>> known_vars;
  for (const auto &var : vars) {
    if (not var.is_unknown()) {
      known_vars->push_back(var);
    }
  }
  return known_vars->empty() ? nullptr : known_vars;
}

void right(std::vector<Variable> &vars, const std::vector<Rule> &rules) {
  std::vector<Rule> vrules{rules};
  auto known_vars = get_known_vars(vars);
  if (not known_vars) {
    std::cerr << "es has no known variables" << std::endl;
    return;
  }
  if (known_vars->size() == vars.size()) {
    std::cerr << "all vars are known" << std::endl;
    return;
  }

  bool _continue = true;
  while (_continue) {
    _continue = false;
    for (size_t i = 0; i < vrules.size(); i++) {
      auto current_rule = vrules.at(i);
      if (not current_rule.is_true(*known_vars)) {
        continue;
      }
      if (not current_rule.conclusion().is_known(*known_vars)) {
        continue;
      }
      _continue = true;
      vrules.erase(vrules.begin() + i);
      known_vars->push_back(current_rule.conclusion());
      i--;

      if (known_vars->size() == vars.size()) {
        return;
      }
    }
  }

}
