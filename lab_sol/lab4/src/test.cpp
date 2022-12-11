// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// void func(vector<string>::iterator begin)
// {
//     *begin="new";
// }
// int main()
// {
//     vector<string> a;
//     a.push_back ("hello");
//     a.push_back ("world");
//     func(a.begin ());
//     cout << *(a.begin());
//     return 0;
// }

#include <cstdio>
#include <ctime>

int main() {
    time_t nowtime;
    struct tm* p;
    time(&nowtime);
    p = localtime(&nowtime);
    printf("%02d%02d%02d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday);
    return 0;
}