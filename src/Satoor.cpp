#include "Satoor.hpp"


Satoor::Satoor() {

}
Satoor::Satoor(std::vector<std::vector<std::string>>& content, std::unordered_map<std::string,std::vector<std::string>>& dict){
    lines.reserve(content.size());

    //parallel loop
    std::for_each(std::execution::par_unseq,content.begin(), content.end(), [&dict,this](std::vector<std::string>& line_content){
        lines.push_back(Satr(line_content,dict,meter_count));
    });
    bool count_not_empty = !meter_count.empty();
    if (count_not_empty)
        closest_meter = meter_count.rbegin()->first;

    std::for_each(std::execution::par_unseq, lines.begin(), lines.end(), [this, &count_not_empty](Satr& line) {
        if (count_not_empty) {
            line.modify_satr_again(closest_meter);
            line.gen_islah();
            line.calculate_ravani_score();
        }
    });

}

void Satoor::edit_line(std::vector<std::string>& line_content, const int& index, std::unordered_map<std::string, std::vector<std::string>>& dict){
    lines[index] = Satr(line_content,dict,closest_meter);
    lines[index].gen_islah();
    lines[index].calculate_ravani_score();
}


void Satoor::print_meter(){
    std::cout<<closest_meter<<std::endl;
}

std::string Satoor::send_meter() {
    return closest_meter;
}

int Satoor::send_length(){
    return lines.size();
}

int Satoor::send_no_of_words(const int &i){
    return lines[i].no_of_words();
}

QStringList Satoor::send_behr(const int &i){
    return lines[i].send_behr();
}

int Satoor::send_ravani_score(const int &i){
    return lines[i].send_ravani_score();
}

QStringList Satoor::send_word_list(const int &i, const int &j){
    return lines[i].send_word_list(j);
}
