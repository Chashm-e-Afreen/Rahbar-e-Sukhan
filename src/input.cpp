#include "input.hpp"

std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(std::move(item));
  }
  return elems;
}

std::string trim(const std::string& str,
                 const std::string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string reduce(const std::string& str,
                   const std::string& fill,
                   const std::string& whitespace)
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}

std::string remove_nuisances(std::string input){
    std::unordered_set<std::string> urduSet {"",
"آ",
"ا",
"ب",
"پ",
"ت",
"ٹ",
"ث",
"ج",
"چ",
"ح",
"خ",
"د",
"ڈ",
"ذ",
"ر",
"ڑ",
"ز",
"ژ",
"س",
"ش",
"ص",
"ض",
"ط",
"ظ",
"ع",
"غ",
"ف",
"ق",
"ک",
"گ",
"ل",
"م",
"ن",
"ں",
"و",
"ہ",
"ھ",
"ی",
"ئ",
"ئے",
"ے",
"ِ",
"ــِ",
"ةٓ",
"ۂ",
"ۂ",
"ۃ",
"ۂ",
"ؤ",
"ۂ"};

    std::string output = "";
    
    UTF8string u8(input);
    for (const std::string &s: u8){
        if(urduSet.count(s)>0|| std::isspace(s[0])){
            output += s;
        }
    }

    return output;
} 

inline std::string& remove_extra_ws_mute(std::string& s)
{
    s.erase(std::unique(std::begin(s), std::end(s), [](unsigned char a, unsigned char b){
        return std::isspace(a) && std::isspace(b);
    }), std::end(s));

    return s;
}

inline std::string remove_extra_ws_copy(std::string s)
{
    return remove_extra_ws_mute(s);
}

std::vector<std::vector<std::string>> split_input(std::string input) {
    
   input = remove_nuisances(input);
   remove_extra_ws_copy(input);
   
   std::vector<std::string> lines = split(input,'\n');
   std::vector<std::vector<std::string>> words = {};

   for (auto s: lines) {
       s = reduce(s);
       if (!s.empty()){
       words.push_back(split(s,' '));
       }
   }
  return words;
}

