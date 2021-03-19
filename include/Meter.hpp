#ifndef METER_HPP
#define METER_HPP
#include <map>
#include <iostream>
#include <unordered_set>
#include <execution>
#include "Lafz.hpp"
#include "utility.hpp"
#include "combination.hpp"

class Meter {
    public: 
        Meter(std::vector<combination>, std::map<std::string,std::size_t>&);
        Meter();
        std::vector<std::string> taskeen_e_ausat(std::string);
        std::vector<std::string> get_meter_family(std::vector<std::string> &v, std::string combination, std::unordered_set<std::string> meter_family);
        void meter_set(std::vector<combination>, std::string, combination& closest, std::vector<std::string> &weights, std::string& behr, std::string& afaeel);
        void enforce_tasbeegh_o_azala(int tasbeegh_o_azala, std::string& closest_meter ,std::string& closest_scansion);
        void check_muqatta(std::string meter);
        void calculate_ravani_score();
        combination functional_set(std::vector<combination> combinations, std::string meter);
        combination find_universal_meter(std::vector<combination> combinations, std::string meter, std::map<std::string, std::size_t>& meters);
        combination check_mozun(combination&  comb, std::map<std::string, std::size_t>& meters);
        combination check_mozun(std::string meter, combination&  comb);
        void print_status(){std::cout<<mozun<<std::endl;};
        bool get_status(){return mozun;};
        void set_name_and_afaeel(const std::string& meter);
        std::vector<std::string> gen_islah(std::vector<std::string> &weights);
        std::string find_closest_meter(std::vector<combination> combinations, std::vector<std::string> meter_family);
        std::string find_universal_meter(std::vector<combination> combinations);
        std::size_t ravani_score();
    private:
        static const std::unordered_set<std::string> ramal_makhboon_musamman;
        static const std::unordered_set<std::string> ramal_makhboon_musaddas;
        static const std::unordered_set<std::string> mujattas_musamman;
        static const std::unordered_set<std::string> khafif_musaddas;
        static const std::unordered_set<std::string> hazaj_musaddas;
        std::vector<std::unordered_set<std::string>> meter_families {ramal_makhboon_musamman,ramal_makhboon_musaddas,mujattas_musamman,khafif_musaddas,hazaj_musaddas};
        std::string meter;
        std::string afaeel;
        std::string name;
        combination closest;
        std::string closest_scansion;
        bool muqatta = false;
        bool mozun = false;
        enum {normal,tasbeegh,azala};
};

#endif // METER_HPP
