//
// Created by alisher on 11/10/20.
//

#ifndef ES_INCLUDE_UTIL_HPP_
#define ES_INCLUDE_UTIL_HPP_

#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>

#include <rule.hpp>
#include <variable.hpp>

std::vector<Rule> loadRulesFromFile(const std::string &filename);
std::vector<Variable> loadVariablesFromFile(const std::string &filename);

#endif //ES_INCLUDE_UTIL_HPP_
