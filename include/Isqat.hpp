#ifndef ISQAT_HPP
#define ISQAT_HPP
#include <string>
#include <unordered_map>
#include <vector>

class Isqat {
    friend struct alif_e_vasl_check;
public:
  Isqat(std::string &,
        std::unordered_map<std::string, std::vector<std::string>> &dict);
  bool isqat_occured(bool status);
  bool last_word();
  std::vector<std::string> isqat_applicable(std::vector<std::string>&, bool is_last_word);
  bool applicable_status();
private:
  bool applicable = false;
  bool can_drop_last_word = false;
  static const std::vector<std::string> suffixes;
  static const std::vector<std::string> last_word_applicable;
};



#endif // ISQAT_HPP
