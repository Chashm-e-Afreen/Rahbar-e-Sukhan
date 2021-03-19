#ifndef COMBINATION_HPP
#define COMBINATION_HPP
#include <bits/c++config.h>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_set>
#include "utility.hpp"

class combination
{
    std::vector<std::string> combination_vector;
    std::string combined;
    std::set<std::size_t> word_end_locations;
    enum {normal,tasbeegh,azala};
public:
    int tasbeegh_o_azala = 0;
    combination(const std::vector<std::string>&, const std::string&, const std::set<std::size_t>& );
    combination();
    std::vector<std::string> gen_islah(bool mozun, std::string closest_meter, std::vector<std::string> &weights);
    bool valid_tasbeegh(std::size_t location);
    int check_tasbeegh_o_azala(std::string &t);
    bool isqat_status(std::size_t);
    bool is_empty(std::string& t);
    bool combination_mozun(std::string& t, const std::string& meter);
    auto vaild_islah(std::vector<std::string> islah);
//    auto get_combination(){return combined;};
    void optimum_islah(std::string&a, std::string& b);
    std::size_t len_diff(std::string& t);
    std::size_t levenshtein_distance(std::string& t);
    friend bool operator< (combination a, combination b) {
        return a.combined < b.combined;
    }
};

template<typename T>
auto gen_combinations (const std::vector<std::vector<T>>& v);


#endif // COMBINATION_HPP
