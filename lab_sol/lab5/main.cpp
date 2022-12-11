#include ".\src\Fraction.h"
using namespace std;

#define JUDGE(x, c, s)                                     \
    {                                                      \
        cout << s << "\t";                                 \
        if (x) {                                           \
            credit += c;                                   \
            cout << "PASS " << c << " " << credit << endl; \
        } else {                                           \
            cout << "FAIL 0" << endl;                      \
        }                                                  \
    }

int main(int argc, char* argv[]) {

    freopen("in.txt", "r", stdin);
    freopen(argv[1], "w", stdout);

    if (argc != 2) {
        exit(-1);
    }

    int credit = 0;

    JUDGE(Fraction().toString() == "0", 1, "Ctor default");
    int num, den;
    cin >> num >> den;
    Fraction frac1(num, den);
    JUDGE(frac1.toString() == "2/3", 1, "Create a Fraction");
    Fraction frac2(frac1);
    JUDGE(frac2.toString() == "2/3", 1, "Copy a Fraction");
    string str = "";
    cin >> str;
    Fraction frac3(str);
    JUDGE(frac3.toString() == "707/500", 1, "Conversion from a finite decimal");
    JUDGE(fabs(frac3.toDouble() - 1.414) < 1e-3, 1, "Type cast to double");
    cin >> num;
    Fraction frac4 = num;
    JUDGE(frac4.toString() == "2", 1, "Takes one integer as parameter");
    Fraction frac5;
    cin >> frac5;
    JUDGE(frac5.toString() == "1/2", 1, "Inserter for streams");
    JUDGE(cout << "out:" << frac2 << " ", 1, "Extractor for streams");
    Fraction frac6 = frac1 + frac5;
    JUDGE(frac6.toString() == "7/6", 1, "Arithmetical operators+");
    Fraction frac7 = frac4 - frac5;
    JUDGE(frac7.toString() == "3/2", 1, "Arithmetical operators-");
    Fraction frac8 = frac7 * frac5;
    JUDGE(frac8.toString() == "3/4", 1, "Arithmetical operators*");
    Fraction frac9 = frac8 / frac1;
    JUDGE(frac9.toString() == "9/8", 1, "Arithmetical operators/");
    JUDGE(frac5 < frac1, 1, "Relational operators<");
    JUDGE(frac1 <= frac2, 1, "Relational operators<=");
    JUDGE(frac2 == frac1, 1, "Relational operators==");
    JUDGE(frac1 != frac8, 1, "Relational operators!=");
    JUDGE(frac1 >= frac2, 1, "Relational operators>=");
    JUDGE(frac3 > frac9, 1, "Relational operators>");

    cout << credit << " / 18" << endl;
}
