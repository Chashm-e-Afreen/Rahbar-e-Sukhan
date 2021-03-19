#include "Lafz.hpp"
#include "utility.hpp"
#include <bits/c++config.h>

Lafz::Lafz(std::string &s,
           std::unordered_map<std::string, std::vector<std::string>> &dict, bool is_last_word)
    : isqat(s, dict) {
    suffix += s.substr(s.size() - 2);
    prefix += s.substr(0, 2);
    std::string zaer = "ِ";
    word = s;
    //    erase_substr(word,zaer);

    if(is_last_word){
        this->is_last_word = true;
    }
    weights = dict[word];

    if (weights.size() == 0) {
        weights = root_search(word, dict);
    }

    weights = isqat.isqat_applicable(weights, is_last_word);

    if (suffix == "ِ" || suffix == "ۂ") {
        kasra = true;
        weights = found_izafat(s, dict, suffix);
    }
    if (prefix == "آ" || prefix == "ا" || word == "و") {
        vasl_or_vao = true;
    }

    switch (weights.size()) {
    case 0:
        not_found = true;
        break;
    default:
        std::unordered_set<std::string> s;
        for (const std::string &i : weights) {
            s.insert(i);
        }
        weights.assign(s.begin(), s.end());
        not_found = false;
    }
}

std::vector<std::string> Lafz::found_izafat(
        std::string &s,
        std::unordered_map<std::string, std::vector<std::string>> &dict,
        std::string &suffix) {

    std::string word = s;

    if (suffix == "ۂ") {
        word.erase(word.end() - suffix.length(), word.end());
        word += "ہ";
        weights = dict[word];
        for (auto &t : weights) {
            t.back() = '1';
            weights.push_back(t + "0");
        }
    } else {
        word.erase(word.end() - suffix.length(), word.end());
        weights = dict[word];
        for (auto &t : weights) {
            if (t.back() == '1') {
                weights.push_back(t + "0");
            } else {
                t.back() = '1';
                weights.push_back(t + "0");
            }
        }
    }

    return weights;
}

void Lafz::alif_e_vasl() {
    for (auto s : weights) {
        auto temp = s.substr(0, s.size() - 1);
        weights.push_back(temp);
    }
}

std::vector<std::string> Lafz::root_search(
        std::string word,
        std::unordered_map<std::string, std::vector<std::string>> &dict) {

    if (ends_with(word, "ن")) {
        weights = root_modify(word, dict, 1, "ں");
    }
    if (ends_with(word, "ں")) {
        weights = root_modify(word, dict, 1, "ن");
        for (auto& t : weights) {
            t.pop_back();
        }
    }
    if (ends_with(word, "یں") || ends_with(word, "وں") || ends_with(word, "ؤں")) {
        if (ends_with(word, "ئیں") || ends_with(word, "ؤں")) {
            weights = root_modify(word, dict, 2, "");
            for (auto& t : weights) {
                t += "10";
            }
        } else {
            weights = root_modify(word, dict, 2, "");
            for (auto& t : weights) {
                t.pop_back();
                t += "10";
            }
        }
    }
    if (ends_with(word, "گی")) {
        weights = root_modify(word, dict, 2, "ہ");
        for (auto& t : weights) {
            t.pop_back();
            t += "10";
        }
    }

    if (ends_with(word, "گاں")) {
        weights = root_modify(word, dict, 3, "ہ");
        for (auto& t : weights) {
            t.pop_back();
            t += "10";
        }
    }

    if (ends_with(word, "اں") && !ends_with(word, "گاں")) {
        weights = root_modify(word, dict, 2, "");
        for (auto& t : weights) {
            t.pop_back();
            t += "10";
        }
    }

    if (ends_with(word, "ے") || ends_with(word, "ی")) {
        if (ends_with(word, "ئے") || ends_with(word, "ئی")) {
            weights = root_modify(word, dict, 2, "");
            for (auto &s : weights) {
                s += "10";
            }
        } else {
            weights = root_modify(word, dict, 1, "ا");
            if (weights.size() == 0) {
                weights = root_modify(word, dict, 1, "ہ");
            }
        }
    }

    return weights;
}

bool Lafz::isqat_applicable() {
    return isqat.applicable_status();
}

std::vector<std::string> Lafz::root_modify(
        std::string word,
        std::unordered_map<std::string, std::vector<std::string>> &dict,
        std::size_t removals, std::string addition) {

    // our unicode chars occupy 2 bytes hence 2x removals
    for (std::size_t i = 0; i < 2 * removals; ++i) {
        word.pop_back();
    }
    if (ends_with(word, "ئ")) {
        word.pop_back();
        word.pop_back();
    }
    word += addition;
    auto weights = dict[word];

    return weights;
}

std::size_t Lafz::isqat_penalty(){
    if (suffix == "ا") {
        return 2;
    }else {
        return 1;
    }
}


