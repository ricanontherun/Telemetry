// Copyright (C) 2016 Christian Roman
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef TELEMETRY_UTILS_REGEXMAP_H
#define TELEMETRY_UTILS_REGEXMAP_H

#include <map>
#include <regex>
#include <stdexcept>

template<class T>
class RegexMap {
 public:
  /**
   * Set a key/expression pair.
   *
   * @param key
   * @param regex
   *
   * @return
   */
  RegexMap<T> &Set(T key, std::string regex);

  /**
   * Test an expression stored at key.
   *
   * @param key
   * @param context
   *
   * @throws std::runtime_error
   * @return
   */
  bool Test(T key, std::string context) const;

  /**
   * Check if a key exists.
   *
   * @param key
   *
   * @return
   */
  bool KeyExists(T key) const;

 protected:
  std::map<T, std::regex> map;
};

template<class T>
RegexMap<T> &RegexMap<T>::Set(T key, std::string regex) {
  this->map[key] = std::regex(regex);

  return *this;
}

template<class T>
bool RegexMap<T>::Test(T key, std::string context) const {
  if (!this->KeyExists(key)) {
    throw std::runtime_error("RegexMap: The provided key not exist.");
  }

  std::regex expression = this->map.find(key)->second;

  return std::regex_match(
      context,
      expression
  );
}

template<class T>
bool RegexMap<T>::KeyExists(T key) const {
  return this->map.find(key) != this->map.end();
}

#endif
