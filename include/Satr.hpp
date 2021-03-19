#ifndef SATR_HPP
#define SATR_HPP

#include "Meter.hpp"
#include "meters.hpp"
#include "utf8_string.hpp"
#include "combination.hpp"
#include <bits/c++config.h>
#include <numeric>
#include <set>
#include <stack>
#include <QObject>
#include <QVariant>
#include <QVector>

class Satr {
public:
  Satr(std::vector<std::string> &,
       std::unordered_map<std::string, std::vector<std::string>> &,
       std::map<std::string, std::size_t> &);
  Satr(std::vector<std::string> &,
       std::unordered_map<std::string, std::vector<std::string>> &,
       std::string closest_meter);
  void gen_islah();
  void modify_satr_again(const std::string &);
  void invoke_alif_e_vasl();
  void calculate_ravani_score();
//  void print_staus() { meter.print_status(); };
  QStringList send_behr();
  QStringList send_word_list(const int& index);
  int send_ravani_score();
  int no_of_words();
private:
  std::vector<Lafz> line;
  std::vector<std::vector<std::string>> weight_combination_words;
  std::vector<combination> combinations;
  std::vector<std::string> words;
  std::vector<std::string> weights;
  std::vector<std::string> islah;
  std::string behr;
  std::string afaeel;
  Meter meter;
  std::size_t ravani_score = 10;
  combination closest;
  bool status;
};


struct alif_e_vasl_check {
    bool valid_visal(const Lafz& a, const Lafz& b);
};


#endif // SATR_HPP
