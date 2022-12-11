#include "book.h"

int main(int argc, char* argv[]) {
    // parameter error
    if (argc != 2) {
        cout << "Error input!" << endl;
        exit(-1);
    }

    string date = argv[1];
    freopen(DIARY_IN, "r", stdin);
    freopen("diary.out", "w+", stdout);
    Book book;
    string temp;

    // read data from a diary that has already been written
    while (!cin.eof()) {
        cin >> temp;
        if (temp == "")
            continue;
        Diary diary;
        diary.set_date(temp);
        while (!cin.eof()) {
            cin >> temp;
            if (temp == ".")
                break;
            diary.add_content(temp);
        }
        book.add_diary(diary);
    }

    // print the diary selected
    book.print(date, date);
    return 0;
}
