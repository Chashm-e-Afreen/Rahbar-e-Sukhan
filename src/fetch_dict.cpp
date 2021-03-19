#include "fetch_dict.hpp"

std::unordered_map<std::string,std::vector<std::string>> fetch_dict(){

    std::unordered_map<std::string,std::vector<std::string>> dict;
    std::string word;
    std::string weight;
    std::ifstream file("Lughat.csv");

    if (!file.is_open()) {
        std::cout << "failed to open"<< '\n';
      }else {
        while(std::getline(file,word,',')){
        std::getline(file,weight);
        dict[word].push_back(weight);
        }
    }
    return dict;
}

