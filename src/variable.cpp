//
// Created by alisher on 11/9/20.
//

#include <iostream>
#include <algorithm>
#include <variable.hpp>

const unsigned int Variable::UNKNOWN = 0;

bool is_number(const std::string &s) {
  return all_of(s.cbegin(), s.cend(), [](const char &c) {
    return isdigit(c);
  });
}

Variable::Variable() {
  name_ = "";
  descriptions_.clear();
  value_ = Variable::UNKNOWN;
}

Variable::Variable(const std::string &name, const std::map<size_t, std::string> &descriptions, size_t val) {
  name_ = name;
  descriptions_ = descriptions;
  value_ = (val > 0 and descriptions.size() > val) ? val : Variable::UNKNOWN;
}

bool Variable::is_unknown() const {
  return value_ == Variable::UNKNOWN;
}

std::ostream &operator<<(std::ostream &os, const Variable &variable) {
  os << variable.name_ << " = " << variable.value_ << std::endl;
  for (const auto&[id, desc]:variable.descriptions_) {
    os << "[" << id << "]: " << desc << std::endl;
  }
  return os;
}

size_t Variable::value() const {
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
    for (const auto &[id, desc]:descriptions_) {
      std::cout << "[" << id << "]: " << desc << std::endl;
    }

    std::cin >> str;
    if (is_number(str)) {
      int x = std::stoi(str);
      if (x <= 0 or x > descriptions_.size() - 1) {
        continue;
      }
      value_ = x;
      return;
    }
  } while (true);
}

bool Variable::is_known(const std::vector<Variable> &facts) const {
  for (const auto &fact:facts) {
    if (fact.name() == name_) {
      return true;
    }
  }
  return false;
}

bool Variable::copyFrom(const rapidjson::Value &value) {
  descriptions_.clear();
  if (not value.IsObject()) {
    std::cerr << "json value is not object type" << std::endl;
    return false;
  }

  if (not value.HasMember("name")) {
    std::cerr << "json value has no member name" << std::endl;
    return false;
  }
  name_ = value["name"].GetString();

  if (value.HasMember("value")) {
    return getValue(value);
  }

  return getValues(value);
}

bool Variable::getValue(const rapidjson::Value &jVal) {
  if (not jVal.HasMember("value")) {
    std::cerr << "json has no value member" << std::endl;
    return false;
  }
  if (not jVal["value"].IsUint()) {
    std::cerr << "value is not uint value" << std::endl;
    return false;
  }
  value_ = jVal["value"].GetUint();
  return true;
}

bool Variable::getValues(const rapidjson::Value &jVar) {
  if (not jVar.HasMember("values")) {
    std::cerr << "has no values array" << std::endl;
    return false;
  }
  for (const auto &jVal:jVar.GetObject()["values"].GetArray()) {
    if (jVal.HasMember("id")) {
      std::cerr << "value has no id member" << std::endl;
      return false;
    }
    if (jVal["id"].IsUint()) {
      std::cerr << "id value is not uint" << std::endl;
      return false;
    }
    if (jVal.HasMember("description")) {
      std::cerr << "value has no description member" << std::endl;
      return false;
    }
    if (jVal["description"].IsString()) {
      std::cerr << "description value is not string" << std::endl;
      return false;
    }

    descriptions_.insert(std::make_pair<uint, std::string>(jVal["id"].GetUint(), jVal["description"].GetString()));
  }
  return true;
}

