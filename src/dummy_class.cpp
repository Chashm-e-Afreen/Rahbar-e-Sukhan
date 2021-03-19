#include "dummy_class.hpp"

dummy_class::dummy_class(){
}
void dummy_class::init(const QString& input){
    QString result;
    auto words = split_input(input.toStdString());
    dict = fetch_dict();
    satoor = Satoor(words,dict);
}

void dummy_class::con_init(const QString &input){
    QFuture<void> future = QtConcurrent::run(this, &dummy_class::init, input);
    while(!future.isFinished()){
        QCoreApplication::processEvents();
    }
}

void dummy_class::edit_line(const QString &updated_input, const int &index){
    QFuture<void> future = QtConcurrent::run([this, &updated_input, &index]() {
        satoor.edit_line(split_input(updated_input.toStdString())[0],index,dict);
    });
    while(!future.isFinished()){
        QCoreApplication::processEvents();
    }
}


QString dummy_class::retrieve_input(const QString& input){
    auto words = split_input(input.toStdString());
    auto dict = fetch_dict();
    Satoor satoor(words,dict);
    return QString::fromUtf8(satoor.send_meter().c_str());
}

int dummy_class::no_of_lines()
{
    return satoor.send_length();
}

int dummy_class::no_of_words(const int &index)
{
    return satoor.send_no_of_words(index);
}

int dummy_class::ravani_score(const int &index)
{
    return satoor.send_ravani_score(index);
}

QStringList dummy_class::send_meter(const int &i)
{
    return satoor.send_behr(i);
}

QStringList dummy_class::send_word_list(const int &i, const int &j)
{
    return satoor.send_word_list(i,j);
}

