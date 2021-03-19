#include "Meter.hpp"
#include "meters.hpp"
#include "utf8_string.hpp"

const std::unordered_set<std::string> Meter::ramal_makhboon_musamman = {
    "10110101110101110101110", "10110101110101110101010",
    "1110101110101110101110", "1110101110101110101010"};
const std::unordered_set<std::string> Meter::ramal_makhboon_musaddas = {
    "10110101110101110", "10110101110101010", "1110101110101110",
    "1110101110101010"};
const std::unordered_set<std::string> Meter::khafif_musaddas = {
    "10110101101101110", "10110101101101010", "1110101101101110",
    "1110101101101010"};
const std::unordered_set<std::string> Meter::mujattas_musamman = {
    "1101101110101101101110", "1101101110101101101010"};
const std::unordered_set<std::string> Meter::hazaj_musaddas = {
    "1010111011011010", "1010101011011010"};

void insert_or_increment(std::map<std::string, std::size_t>& meters, std::string meter, std::size_t add){
    if (meters.contains(meter)) {
        meters[meter] += add;
    } else {
        meters.emplace(meter, add);
    }
}
void Meter::set_name_and_afaeel(const std::string& meter){
    this->meter = meter;
    afaeel = METERS.at(meter);
    name = NAMES.at(meter);
}
Meter::Meter(std::vector<combination> combinations,
             std::map<std::string, std::size_t>& meters) {
    std::string closest_meter = "";

    for (auto&i : combinations){
        combination check = check_mozun(i, meters);
        if (!check.is_empty(closest_meter)){
            closest = i;
            return;
        }
    }
    std::for_each(std::execution::par_unseq, combinations.begin(), combinations.end(), [this,&closest_meter](combination& i){
        combination check = check_mozun(closest_meter,i);
        if (!check.is_empty(closest_meter)){
            closest = i;
        }
    });

    closest_meter =  find_universal_meter(combinations);

    if (closest_meter != ""){
        insert_or_increment(meters,closest_meter,1);
//        set_name_and_afaeel(closest_meter);
    }
}



void Meter::meter_set(std::vector<combination> combinations,
                      std::string closest_meter, combination &closest, std::vector<std::string>& weights, std::string& behr, std::string& afaeel) {

    for (auto&i : combinations){
        combination check = check_mozun(closest_meter,i);
        if (!check.is_empty(closest_meter)){
            // set_name_and_afaeel(closest_meter);
            // gen_islah(weights);
            this->closest = i;
            closest = this->closest;
            behr = this->name;
            afaeel = this->afaeel;
            return;
        }
    }


    std::vector<std::string> meter_family = taskeen_e_ausat(closest_meter);

    closest_meter = find_closest_meter(combinations,meter_family);

    if (combinations.size() == 1) this->closest = combinations[0];
    
    set_name_and_afaeel(closest_meter);
    gen_islah(weights);
    closest = this->closest;
    behr = this->name;
    afaeel = this->afaeel;
}


std::string Meter::find_universal_meter(std::vector<combination> combinations) {
    auto closest_meter =  std::min_element(std::execution::par_unseq,METERLIST.begin(),METERLIST.end(), [&combinations,this](std::string a, std::string b) {
                auto closest1 = functional_set(combinations,a);
                auto closest2 = functional_set(combinations,b);

                if (closest1.combination_mozun(closest_scansion, a)){
                    closest = closest1;
                    return true;
                }
                if (closest1.combination_mozun(closest_scansion, b)){
                    closest = closest2;
                    return false;
                }
                bool condition = closest1.levenshtein_distance(a) < closest2.levenshtein_distance(b);
                closest = condition ? closest1 : closest2;

                return condition;
    });
    return *closest_meter;
}


std::size_t occurences(std::string& str_to_search, const std::string& sub){
    std::size_t nPos = str_to_search.find(sub, 0);
    std::size_t count = 0;
    while (nPos != std::string::npos)
    {
        count += 1;
        nPos = str_to_search.find(sub, nPos + sub.size());
    }
    return count;
}
std::size_t Meter::ravani_score(){
    std::size_t initial = occurences(meter,"1110");
    
    
    if (mozun) {
        return 10 + initial;
    }
    return 0;
}


std::string Meter::find_closest_meter(std::vector<combination> combinations, std::vector<std::string> meter_family) {
    if (meter_family.size() == 1) {
        closest = functional_set(combinations, meter_family[0]);
        return meter_family[0];
    }
        
    auto closest_meter =  std::min_element(std::execution::par_unseq,meter_family.begin(),meter_family.end(), [&combinations,this](std::string a, std::string b) {
                auto closest1 = functional_set(combinations,a);
                auto closest2 = functional_set(combinations,b);
                if (closest1.combination_mozun(closest_scansion,a)){
                    closest = closest1;
                    mozun = true;
                    return true;
                }
                if (closest2.combination_mozun(closest_scansion,b)){
                    closest = closest2;
                    mozun = true;
                    return false;
                }

                bool condition = closest1.levenshtein_distance(a) < closest2.levenshtein_distance(b);
                closest = condition ? closest1 : closest2;
                return condition;
    });

    return *closest_meter;
}
combination Meter::check_mozun(combination& j, std::map<std::string, std::size_t>& meters){
    std::string scansion;
    int tasbeegh_o_azala = j.check_tasbeegh_o_azala(scansion);
    if (tasbeegh_o_azala == tasbeegh || tasbeegh_o_azala == azala) {
        scansion.pop_back();
    }
    if (METERS.contains(scansion)) {
        closest_scansion = scansion;
        insert_or_increment(meters,scansion,5);
        return j;
    }

    std::size_t location = scansion.length() / 2;
    std::string temp_meter = scansion.substr(0,location) + scansion.substr(location+1);
    check_muqatta(temp_meter);


    if(METERS.contains(temp_meter) && muqatta){
        if (j.valid_tasbeegh(location+1)) {
            meter = temp_meter;
            closest_scansion = scansion;
            insert_or_increment(meters,meter,5);
            return j;
        }

    }

    return combination();
}

combination Meter::check_mozun(std::string meter, combination& j){
    std::string scansion;
    int tasbeegh_o_azala = j.check_tasbeegh_o_azala(scansion);

    if (METERS.contains(scansion) && meter == scansion) {
        set_name_and_afaeel(scansion);
        closest_scansion = scansion;
        mozun = true;
        return j;
    }
    auto dist = iosifovitch::levenshtein_distance(scansion,meter);
    if (dist == 1){
        check_muqatta(meter);
        if(muqatta){
            std::string temp_meter(meter);
            std::size_t location = temp_meter.length() / 2;
            temp_meter.insert(location, "1");

            if (temp_meter == scansion &&
                    j.valid_tasbeegh(location)) {
                set_name_and_afaeel(meter);
                mozun = true;
                closest_scansion = temp_meter;
                enforce_tasbeegh_o_azala(tasbeegh_o_azala,meter,scansion);
                return j;
            }

        }
    }
    return combination();
}

combination Meter::functional_set(std::vector<combination> combinations, std::string meter){
    combination result;

        result = *std::min_element(combinations.begin(), combinations.end(),[&meter](combination& a, combination& b){
            auto len_diff = a.len_diff(meter);
            //unordered if len_diff>5
            return (len_diff < 5) && (a.levenshtein_distance(meter) < b.levenshtein_distance(meter));
        });
    return result;
}

void Meter::enforce_tasbeegh_o_azala(int tasbeegh_o_azala,
                                     std::string& closest_meter,
                                     std::string& closest_scansion) {
    switch (tasbeegh_o_azala) {
    case tasbeegh:
        closest_scansion += "1";
        closest_meter += "1";
        afaeel.pop_back(); // twice for an Urdu character
        afaeel.pop_back();
        afaeel += "ان";
        name += " مسبغ";
        break;
    case azala:
        closest_scansion += "1";
        closest_meter += "1";
        afaeel.pop_back(); // twice for an Urdu character
        afaeel.pop_back();
        afaeel += "ان";
        name += " مذال";
        break;
    default:
        if (mozun && muqatta){
            std::string temp;
            temp = closest_scansion.substr(0, closest_scansion.length()/2 + 1);
            //UTF-8 at it again
            afaeel.insert(afaeel.length()/2 - 2, "ا");

            if (ends_with(temp, "0101")){
                if (!ends_with(name, "مسبغ")){
                    name += " مسبغ";
                }
            }
            if (ends_with(temp, "1101")){
                if (!ends_with(name, "مذال")){
                    name += " مذال";
                }
            }
        } else {
            set_name_and_afaeel(closest_meter);
        }
    }
}

std::vector<std::string> Meter::taskeen_e_ausat(std::string combination) {
    std::vector<std::string> v;
    std::for_each(std::execution::par_unseq,meter_families.begin(), meter_families.end(), [&v,this,combination](std::unordered_set<std::string> i){
        v = get_meter_family(v,combination,i);
    });
    // for (auto &i : meter_families) {
    //     v = get_meter_family(v, combination, i);
    // }
    if (v.empty()) {
        v.push_back(combination);
    }
    return v;
}

std::vector<std::string>
Meter::get_meter_family(std::vector<std::string> &v, std::string combination,
                        std::unordered_set<std::string> meter_family) {
    if (meter_family.contains(combination)) {
        for (const auto &i : meter_family) {
            v.push_back(i);
        }
    }
    return v;
}

void Meter::check_muqatta(std::string meter) {
    auto first_half = meter.substr(0, meter.length() / 2);
    auto second_half = meter.substr(meter.length() / 2, meter.length()-1);
    auto first_quarter = first_half.substr(0, first_half.length() / 2);
    auto second_quarter =
            first_half.substr(first_half.length() / 2, first_half.length()-1);

    if (first_half == second_half && first_quarter != second_quarter) {
        muqatta = true;
    }
}

std::vector<std::string> Meter::gen_islah(std::vector<std::string>& weights){
    return closest.gen_islah(mozun,meter,weights);
}

Meter::Meter() { meter = ""; }


