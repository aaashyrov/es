//
// Created by alisher on 11/9/20.
//

#ifndef ES_INCLUDE_VARIABLE_HPP_
#define ES_INCLUDE_VARIABLE_HPP_
#include <string>
#include <vector>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <map>

class Variable {
 public:
  static const unsigned int UNKNOWN;

  Variable();
  Variable(const std::string &name, const std::map<size_t, std::string> &descriptions, size_t val = Variable::UNKNOWN);
  ~Variable() = default;

  void get();
  size_t value() const;
  bool is_unknown() const;
  const std::string &name() const;
  bool copyFrom(const rapidjson::Value &value);
  bool is_known(const std::vector<Variable> &facts) const;

  friend std::ostream &operator<<(std::ostream &os, const Variable &variable);

 protected:

  bool getValue(const rapidjson::Value &jVal);
  bool getValues(const rapidjson::Value &jVar);

  size_t value_;
  std::string name_;
  std::map<size_t, std::string> descriptions_;
};

#endif //ES_INCLUDE_VARIABLE_HPP_
