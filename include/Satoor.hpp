#ifndef SATOOR_HPP
#define SATOOR_HPP

#include "Satr.hpp"

#include <iostream>
#include <QObject>
#include <QDebug>
#include <QQuickView>
#include <QQuickItem>
#include <QtConcurrent/QtConcurrent>
#include <execution>

class Satoor {
public:
    Satoor(std::vector<std::vector<std::string>>&, std::unordered_map<std::string,std::vector<std::string>>&);
    Satoor();
    void print_meter();
    void edit_line(std::vector<std::string> &content, const int &index, std::unordered_map<std::string,std::vector<std::string>>&dict);
    std::string send_meter();
    int send_length();
    int send_no_of_words(const int& i);
    int send_ravani_score(const int& i);
    QStringList send_behr(const int& i);
    QStringList send_word_list(const int& i, const int& j);
private:
    std::vector<Satr> lines;
    std::map<std::string, std::size_t> meter_count;
    std::string closest_meter;
};

#endif // SATOOR_HPP
