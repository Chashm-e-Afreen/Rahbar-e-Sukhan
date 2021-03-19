#ifndef INPUT_HPP
#define INPUT_HPP
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include "utf8_string.hpp"


std::vector<std::string> split(const std::string &s, char delim);
std::string trim(const std::string& str,
                 const std::string& whitespace = " \n");
std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");
std::string remove_spaces(std::string input);
std::string remove_nuisances(std::string input);
inline std::string& remove_extra_ws_mute(std::string& s);
inline std::string remove_extra_ws_copy(std::string s);
std::vector<std::vector<std::string>> split_input(std::string input);



#endif
