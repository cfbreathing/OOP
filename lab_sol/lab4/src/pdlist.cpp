#include "book.h"

int main(int argc, char* argv[]) {
    freopen(DIARY_ST, "r", stdin);     // redirection the stdin
    freopen(DIARY_OUT, "w+", stdout);  // redirection the stdout
    string temp;
    Book book;

    string start, end;
    if (argc == 3)
        start = argv[1], end = argv[2];
    else if (argc != 1) {
        cout << "Error input!" << endl;  // parameter error
        exit(-1);
    }

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

    // print the diary
    if (argc > 2)
        book.print(start, end);
    else
        book.print();
    return 0;
}
