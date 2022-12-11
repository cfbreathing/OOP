/*
 * @File: diary.h
 * @Author: Wenjie Luo
 * @Usage: Function declaration.
 * @date: 2022.11.11
 */
#pragma once
#ifndef _DIARY_H_
#define _DIARY_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Diary {
   private:
    string date;             // the date when diary written
    vector<string> content;  // the content of the diary

   public:
    Diary();  // default initialization
    ~Diary();
    Diary(const string&);                     // initialisation with a date
    void reset();                             // reset a diary
    void set_content(const vector<string>&);  // set the content of a diary
    void set_date(const string&);             // set the date of a diary
    void add_content(const string&);          // add content to a diary
    string get_date();                        // get the date
    vector<string> get_content();             // get the content
    void print();  // print the date and content to stdout
};

#endif
