#ifndef LAFZ_HPP
#define LAFZ_HPP
#include "Isqat.hpp"
#include <string>
#include <unordered_set>
#include <vector>

class Lafz {
      friend struct alif_e_vasl_check;
public:

  Lafz(std::string &,
       std::unordered_map<std::string, std::vector<std::string>> &, bool is_last_word);
  std::vector<std::string>
  found_izafat(std::string &,
               std::unordered_map<std::string, std::vector<std::string>> &,
               std::string &);
  void alif_e_vasl();
  void word_vao();
  std::vector<std::string>
  root_search(std::string,
              std::unordered_map<std::string, std::vector<std::string>> &);
  std::vector<std::string>
  root_modify(std::string,
              std::unordered_map<std::string, std::vector<std::string>> &,
              std::size_t, std::string);
  std::size_t isqat_penalty();
  bool isqat_applicable();

private:
  friend class Satr;
  friend class dummy_class;
  std::string word;
  std::string suffix = "";
  std::string prefix = "";
  std::vector<std::string> weights;
  std::string islah;
  bool kasra = false;
  bool problematic;
  bool vasl_or_vao = false;
  bool not_found;
  bool is_last_word = false;
  Isqat isqat;
};

#endif // LAFZ_HPP
