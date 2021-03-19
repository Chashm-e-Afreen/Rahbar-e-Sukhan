#include "Isqat.hpp"
#include "utility.hpp"

const std::vector<std::string> Isqat::suffixes  = {"ا", "ہ", "ی", "ے", "ؤں", "ؤ", "یں", "وں", "و"};
const std::vector<std::string> Isqat::last_word_applicable  = {"ئی","ئے", "ؤں", "ؤ"};

Isqat::Isqat(std::string &word, std::unordered_map<std::string,std::vector<std::string>> &dict){
    for (const auto &s : suffixes) {
        if (ends_with(word,s)){
            applicable = true;
        }
        if (ends_with(word,"یں")|| ends_with(word,"وں")) {
             auto temp = word.substr(0, word.size()-2) + "ن";
             if(dict[temp].size() == 0){
             applicable = true;
             can_drop_last_word = true;
            }
        }
    }
    for (const auto &s : last_word_applicable) {
        if (ends_with(word,s)){
            can_drop_last_word = true;
        }
    }

}

bool Isqat::isqat_occured(bool status) {
    return applicable && status;
}

bool Isqat::last_word() {
    return applicable && can_drop_last_word;
}
bool Isqat::applicable_status() {
    return applicable;
}

std::vector<std::string> Isqat::isqat_applicable(std::vector<std::string>& weights, bool is_last_word){
    if (applicable) {
        for (auto &weight: weights) {
            if (ends_with(weight, "0")){
                auto temp = weight.substr(0, weight.size() - 1);
                if (!temp.empty() && (!is_last_word || last_word())) {
                    weights.push_back(temp);
                    }
                }
            }
        }
    return weights;
}

