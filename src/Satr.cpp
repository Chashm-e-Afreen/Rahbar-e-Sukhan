#include "Satr.hpp"

template <typename T>
auto gen_combinations(const std::vector<std::vector<T>> &v) {
    std::vector<std::vector<T>> s = {{}};
    
    for (const auto &u : v) {
        std::vector<std::vector<T>> r;
        for (const auto &x : s) {
            for (const auto y : u) {
                r.push_back(x);
                r.back().push_back(y);
            }
        }
        s = std::move(r);
    }

    std::string combined;
    std::vector<combination> combinations;
    combinations.reserve(s.size());

    for (const auto &i : s) {
        combined = "";
        std::size_t end_location = -1;
        std::set<std::size_t> word_end_locations;

        for (const auto &j : i) {
            combined += j;
            end_location += j.length();
            word_end_locations.insert(end_location);
        }

        auto temp = combination(i, combined, word_end_locations);
        combinations.push_back(temp);
    }
if (!combinations.empty()) {
    std::sort(combinations.begin(), combinations.end(), [](combination & a, combination & b) {
        return a < b;
    });
    combinations.erase(std::unique(combinations.begin(), combinations.end(), [](combination & a, combination & b) {
        return a < b;
    }));
}
    return combinations;
}

bool alif_e_vasl_check::valid_visal(const Lafz& a, const Lafz& b) {
    return a.vasl_or_vao && !b.isqat.applicable;
}

void Satr::invoke_alif_e_vasl() {

    for (std::size_t i = 0; i < line.size() - 1; ++i) {
        alif_e_vasl_check check;

        if (check.valid_visal(line[i+1],line[i])) {
            for (std::size_t j = 0; j <weight_combination_words[i].size(); ++j) {
                auto temp = weight_combination_words[i][j].substr(0, weight_combination_words[i][j].size() - 1);
                if (!temp.empty()) {
                    weight_combination_words[i].push_back(temp);
                }
            }
        }
    }
}

Satr::Satr(std::vector<std::string> &line_content,
           std::unordered_map<std::string, std::vector<std::string>> &dict,
           std::map<std::string, std::size_t> &meter_count) {
    line.reserve(line_content.size());
    for (auto &i : line_content) {
        words.push_back(i);
        auto temp = Lafz(i, dict, i==line_content.back());
        line.push_back(temp);
        weight_combination_words.push_back(temp.weights);
    }

    invoke_alif_e_vasl();
    combinations = gen_combinations(weight_combination_words);

    if (!combinations.empty())
        meter = Meter(combinations, meter_count);
}
//Constructor for live editing
Satr::Satr(std::vector<std::string> &line_content, std::unordered_map<std::string, std::vector<std::string> > &dict, std::string closest_meter){
    line.reserve(line_content.size());
    for (auto &i : line_content) {
        words.push_back(i);
        auto temp = Lafz(i, dict, i==line_content.back());
        line.push_back(temp);
        weight_combination_words.push_back(temp.weights);
    }

    invoke_alif_e_vasl();
    combinations = gen_combinations(weight_combination_words);
    if (!combinations.empty())
        meter.meter_set(combinations, closest_meter, closest,weights,behr,afaeel);
}

void Satr::gen_islah(){
    islah = meter.gen_islah(weights);
}

void Satr::modify_satr_again(const std::string &meter_closest) {
    behr = NAMES.at(meter_closest);
    afaeel = METERS.at(meter_closest);
    meter.meter_set(combinations, meter_closest, closest,weights,behr,afaeel);
}



void Satr::calculate_ravani_score() {
    ravani_score = meter.ravani_score();

    if (ravani_score >= 10) {
        for (std::size_t i=0; i< line.size(); ++i){
            if (line[i].isqat_applicable() && closest.isqat_status(i)) {
                ravani_score -= line[i].isqat_penalty();
            }
        }
    }
    if (ravani_score>10) ravani_score = 10;
}


std::string get_urdu_numerals(std::string& input){
    std::string output;
    for (const auto&c : input){
        c == '1' ? output += "۱": output += "۰";
    }
    UTF8string u8(output);
    u8.utf8_reverse();
    return std::string(u8.utf8_str());
}


QStringList Satr::send_behr(){
    auto behr = QString::fromUtf8((this->behr.c_str()));
    auto afaeel = QString::fromUtf8((this->afaeel.c_str()));
    
    return {behr,afaeel};
}

QStringList Satr::send_word_list(const int& index){
    QStringList word_list;
    auto lafz = QString::fromUtf8((this->words[index].c_str()));
    QString taqti;
    QString islah;
    if (!this->weights.empty()) {
        taqti = QString::fromUtf8((get_urdu_numerals(this->weights[index]).c_str()));
        islah = QString::fromUtf8((get_urdu_numerals(this->islah[index]).c_str()));
    } else {
        bool not_found = this->weight_combination_words[index].empty();
        taqti = not_found ? "N/A" : QString::fromUtf8(weight_combination_words[index][0].c_str());
        islah = "N/A";
    }
    word_list.append({lafz,taqti,islah});
    return word_list;
}

int Satr::send_ravani_score(){
    return ravani_score;
}

int Satr::no_of_words(){
    return words.size();
}

