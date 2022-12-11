/*
 * @File: diary.h
 * @Author: Wenjie Luo
 * @Usage: Defining function in book.h
 * Integrating many diary's into one operation at the same time.
 * @date: 2022.11.11
 */
#include "book.h"
typedef vector<Diary>::iterator pages;

// sort diary in terms of date
bool cmp(Diary a, Diary b) {
    return atoi(a.get_date().c_str()) < atoi(b.get_date().c_str());
}

Book::Book() {
    my_diary.empty();
}

Book::~Book() {
    my_diary.empty();
}

pages Book::find(const string& data) {
    for (auto i = my_diary.begin(); i != my_diary.end(); i++) {
        if (i->get_date() == data) {
            return i;
        }
    }
    return my_diary.end();
}

int Book::erase_diary(const string& data) {
    pages i = find(data);
    if (i != my_diary.end()) {
        my_diary.erase(i);
        i->reset();  // recycle memory
        return 0;
    }
    return -1;
}

void Book::add_diary(Diary new_diary) {
    pages i = find(new_diary.get_date());
    if (i == my_diary.end()) {
        my_diary.push_back(new_diary);  // if you haven't written a diary on
                                        // this day, write one
    } else {
        i->set_content(
            new_diary.get_content());  // if there is already a diary for the
                                       // same date, reset its contents
    }
}

void Book::my_sort() {
    sort(my_diary.begin(), my_diary.end(), cmp);
}

void Book::print() {
    for (pages i = my_diary.begin(); i != my_diary.end(); i++)
        i->print();
}

void Book::print(const string& start, const string& end) {
    for (pages i = my_diary.begin(); i != my_diary.end(); i++)
        if (i->get_date() >= start && i->get_date() <= end)
            i->print();  // output the diary for the specified date
}