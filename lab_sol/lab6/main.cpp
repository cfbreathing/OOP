#include "Vector.h"

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
    int credit = 0, x;
    Vector<int> v1;
    JUDGE(v1.empty() == true, 1, "Create an empty vector.");
    Vector<int> v2(10);
    JUDGE(v2.empty() == true, 1,
          "Creates a vector for holding 'size' elements.");
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        v2.push_back(x);
    }
    JUDGE(v2[0] == 2, 1,
          "Accesses the specified element without bounds checking");
    JUDGE(v2[1] == 3 && v2[2] == 5 && v2[3] == 7 && v2[4] == 11, 1,
          "Adds an element to the end.");
    Vector<int> v3(v2);
    JUDGE(v3.size() == v2.size() && v3[4] == 11, 1, "The copy ctor.");
    cin >> x;
    v3.push_back(x);
    JUDGE(v3.size() == 6, 1, "Return the size of the container");
    JUDGE(v3.at(5) == 13, 1,
          "Accesses the specified element with bounds checking");
    try {
        int x = v3.at(6);
    } catch (out_of_range err) {
        string str(err.what());
        JUDGE(str == "index out of range.", 1,
              "Throws an exception of when index <0 or >=m_nSize");
    }
    v2.clear();
    JUDGE(v2.size() == 0 && v2[1] == 3, 1, "Clears the contents");
    for (int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        v3.push_back(x);
    }
    JUDGE(v3.size() == 12 && v3[10] == 31 && v3[1] == 3, 1,
          "Expand the storage of the container to a new capacity");
    cout << credit << " / 10" << endl;
}
