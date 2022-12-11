/*
 * @File: book.h
 * @Author: Wenjie Luo
 * @Usage: Function declaration.
 * @date: 2022.11.11
 */
#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#define DIARY_ST "diary.txt"   // where the diary is stored
#define DIARY_IN "diary.in"    // where the diary is input
#define DIARY_OUT "diary.out"  // where the outcome is ouput

#include "diary.h"
class Book {
    vector<Diary> my_diary;  // the diary book

   public:
    Book();  // default initialization
    ~Book();
    vector<Diary>::iterator find(const string&);  // dind a diary
    int erase_diary(const string&);               // erase a diary
    void my_sort();                               // sort the diary
    void add_diary(Diary);                        // add a new diary
    void print();                                 // pirnt the all diary
    void print(const string&, const string&);     // pirnt part of diary
};

#endif