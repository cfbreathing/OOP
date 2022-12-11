#include "book.h"

int main(int argc, char* argv[]) {
    Book book;

    // if no parameters are entered, the predetermined data will be used
    if (argc == 1) {
        freopen(DIARY_IN, "r", stdin);  // redirection the stdin
        string temp;
        while (!cin.eof()) {
            Diary diary;
            cin >> temp;
            diary.set_date(temp);
            while (!cin.eof() && temp != ".") {
                cin >> temp;
                diary.add_content(temp);
            }
            // push diary into the book
            book.add_diary(diary);
        }
    } else if (argc > 2) {  // you can also enter the diary yourself
        string date;
        cin >> date;
        Diary diary(date);
        string temp;
        while (!cin.eof() && temp != ".") {
            cin >> temp;
            diary.add_content(temp);
        }
        book.add_diary(diary);
    }
    // save the book
    cout << "Have a nice day!" << endl;
    freopen(DIARY_ST, "w+", stdout);  // redirection the stdout
    book.my_sort();
    book.print();
    return 0;
}
