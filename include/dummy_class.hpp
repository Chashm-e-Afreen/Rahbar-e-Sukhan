#ifndef DUMMY_CLASS_HPP
#define DUMMY_CLASS_HPP

#include <QObject>
#include <QDebug>
//#include <QQmlEngine>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include "Satoor.hpp"
#include "fetch_dict.hpp"
#include "input.hpp"
#include "Satr.hpp"

class dummy_class : public QObject
{
    Q_OBJECT
Q_SIGNALS:
   void send_to_qml(std::string);
//    void result_ready(const QString& result);
//
public Q_SLOTS:
    QString retrieve_input(const QString& input);
    int no_of_lines();
    int no_of_words(const int& index);
    int ravani_score(const int& index);
    QStringList send_meter(const int& i);
    QStringList send_word_list(const int& i, const int&j);
    void init (const QString& input);
    void con_init(const QString& input);
    void edit_line(const QString& updated_input, const int& index);
public:
    dummy_class();
private:
    Satoor satoor;
    std::unordered_map<std::string,std::vector<std::string>> dict;
};

#endif // DUMMY_CLASS_HPP
