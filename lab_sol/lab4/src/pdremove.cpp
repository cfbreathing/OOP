#include "book.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) { // parameter error
        cout << "Error input!" << endl;
        exit(-1);
    }
    
    string date = argv[1];
    freopen(DIARY_ST, "r", stdin);
    Book book;
    string temp;
    // read data from a diary that has already been written
    while (!cin.eof()) {
        cin >> temp;
        if (temp == "")
            continue;
        Diary diary;
        diary.set_date(temp);
        while (!cin.eof() && temp != ".") {
            cin >> temp;
            diary.add_content(temp);
        }
        book.add_diary(diary);
    }
    // remove the diary selected
    int flag = book.erase_diary(date);

    // save the book
    freopen(DIARY_ST, "w", stdout);
    book.print();

    return flag;
}
