//
// Created by alisher on 11/10/20.
//
#include <fstream>
#include <iostream>

#include <rapidjson/istreamwrapper.h>

#include <util.hpp>

std::vector<Rule> loadRulesFromFile(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (not file.is_open()) {
    std::cerr << "file can't open" << std::endl;
    return std::vector<Rule>{};
  }
  rapidjson::IStreamWrapper jfile(file);
  rapidjson::Document document;
  document.ParseStream(jfile);
  file.close();

  if (not document.IsObject()) {
    std::cerr << "file is not an object" << std::endl;
    return std::vector<Rule>{};
  }

  if (not document.GetObject().HasMember("rules")) {
    std::cerr << "file has no rules array" << std::endl;
    return std::vector<Rule>{};
  }

  if (not document.GetObject()["rules"].IsArray()) {
    std::cerr << "rules is not an array" << std::endl;
    return std::vector<Rule>{};
  }

  std::vector<Rule> rules;
  for (const auto &jRule:document.GetObject()["rules"].GetArray()) {
    Rule rule;
    if (not rule.copyFrom(jRule)) {
      std::cerr << "rule was not parsed" << std::endl;
      return std::vector<Rule>{};
    }
    rules.push_back(rule);
  }
  return rules;
}

std::vector<Variable> loadVariablesFromFile(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (not file.is_open()) {
    std::cerr << "file can't open" << std::endl;
    return std::vector<Variable>{};
  }
  rapidjson::IStreamWrapper jfile(file);
  rapidjson::Document document;
  document.ParseStream(jfile);
  file.close();

  if (not document.IsObject()) {
    std::cerr << "file is not an object" << std::endl;
    return std::vector<Variable>{};
  }

  if (not document.GetObject().HasMember("variables")) {
    std::cerr << "file has no variables array" << std::endl;
    return std::vector<Variable>{};
  }

  if (not document.GetObject()["variables"].IsArray()) {
    std::cerr << "variables is not an array" << std::endl;
    return std::vector<Variable>{};
  }

  std::vector<Variable> vars;
  for (const auto &jVar:document.GetObject()["variables"].GetArray()) {
    Variable variable;
    if (not variable.copyFrom(jVar)) {
      std::cerr << "variable was not parsed" << std::endl;
      return std::vector<Variable>{};
    }
    vars.push_back(variable);
  }
  return vars;
}
