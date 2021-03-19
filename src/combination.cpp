#include "combination.hpp"
#include "meters.hpp"


combination::combination(const std::vector<std::string> &comb_vec,
                         const std::string &combination,
                         const std::set<std::size_t> &word_end_loc) {
  combination_vector = comb_vec;
  combined = combination;
  word_end_locations = word_end_loc;
}

bool combination::valid_tasbeegh(std::size_t location) {
  return word_end_locations.contains(location);
}

bool combination::isqat_status(std::size_t index) {
  if (index < combination_vector.size()) {
    return ends_with(combination_vector[index], "1");
  }
  return false;
}

combination::combination() {
    combined = "";
    combination_vector = {};
    word_end_locations = {};
}
int combination::check_tasbeegh_o_azala(std::string &t) {
    t = combined;
  if (ends_with(combined, "0101")) {
          t.pop_back();
    tasbeegh_o_azala = tasbeegh;
    return tasbeegh;
  } else if (ends_with(combined, "1101")) {
          t.pop_back();
    tasbeegh_o_azala = azala;
    return azala;
  }
  return normal;
}

auto combination::vaild_islah(std::vector<std::string> islah) {

    if (!islah.empty()){
        for (std::size_t i = islah.size()-1; i>=1; --i) {
            if (islah[i].starts_with("0")) {
                islah[i] = "1" + islah[i];
                islah[i-1].pop_back();
            }
            if (islah[i-1] != combination_vector[i-1]){
                if (islah[i-1].ends_with("1") && "1" + islah[i] == combination_vector[i]) {
                    islah[i-1].pop_back();
                    islah[i] = "1" + islah[i];
                }
            }
        }
    }
    return islah;
}



void char_not(char& a) {
    if (a == '0')
        a = 1;
    else
        a = 0;
}
std::vector<std::string> combination::gen_islah(bool mozun, std::string closest_meter, std::vector<std::string>& weights) {
    weights = combination_vector;
    if (mozun) {
        return combination_vector;
    }

    std::vector<std::string> islah;
    std::size_t prev = 0;

    for (const auto &i: word_end_locations) {
        std::string temp;
        if (i <= closest_meter.length()) {
            temp = closest_meter.substr(prev,i+1-prev);
            if (i == *word_end_locations.rbegin())
                temp = closest_meter.substr(prev);
        } 
        islah.push_back(temp);
        prev = i + 1;
    }
    islah = vaild_islah(islah);
    return islah;
}

bool combination::is_empty(std::string &t) {
    bool empty = combined == "";
    if (!empty) t = combined;
    return empty;
}

bool combination::combination_mozun(std::string& t, const std::string& meter) {
    bool mozun =  METERS.contains(combined);
    if (mozun) 
        t = combined;
    return mozun && meter == combined;
}


std::size_t combination::len_diff(std::string &t){
    return abs_diff(combined.length(), t.length());
}


std::size_t combination::levenshtein_distance(std::string &t){
    return iosifovitch::levenshtein_distance(t,combined);
}
