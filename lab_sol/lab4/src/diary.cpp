/*
 * @File: diary.cpp
 * @Author: Wenjie Luo
 * @Usage: Defining function in diary.h
 * Implement basic operations on diary.
 * @date: 2022.11.11         
*/
#include "diary.h"

Diary::Diary() {
    date.erase();
    content.empty();
}

Diary::~Diary() {

}

Diary::Diary(const string& date) {
    this->date = date;
    content.empty();
}

void Diary::reset() {
    date.erase();
    content.empty();
}

void Diary::set_content(const vector<string>& content) {
    this->content = content;
}

void Diary::set_date(const string& date) {
    this->date = date;
}

void Diary::add_content(const string& new_content) {
    this->content.push_back(new_content);
}

string Diary::get_date() {
    return this->date;
}

vector<string> Diary::get_content() {
    return this->content;
}


void Diary::print() {
    cout << date << endl;
    for (auto i = content.begin(); i != content.end(); i++)
        cout << *i << endl;
}

