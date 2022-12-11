#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class student {
public:
    string name;
    int score1;
    int score2;
    int score3;
    float average;
};
class course {
public:
    float sum;
    int min;
    int max;
    void get(student &, int);
    void init( );
};
//初始化函数，让每门课程的数据初始化
void course::init( ){
    sum = 0;
    max = 0;
    min = 6;
};
//用于获取每门课程的最大、最小和平均值
void course::get(student &s, int n){
    if(n == 1){
        sum += s.score1;
        if(s.score1 > max) max = s.score1;
        if(s.score1 < min) min = s.score1;
    }else if(n == 2){
        sum += s.score2;
        if(s.score2 > max) max = s.score2;
        if(s.score2 < min) min = s.score2;        
    }else if(n == 3){
        sum += s.score3;
        if(s.score3 > max) max = s.score3;
        if(s.score3 < min) min = s.score3;             
    }else exit(-1);
};
int main() {
    //开始输入
    cout << "This program used to record 10 students' information." << endl;
    //实例化学生和科目
    student Stu[10];
    course Cou[3];
    //依次对科目类进行初始化
    for(int i = 0; i < 3; i++){
        Cou[i].init();
    }
    int count = 0;
    //开始依次读入每个学生的名字、成绩
    while( count < 10){
        cout <<"Enter the " << count + 1 << " student' name" << endl;;
        cin >> Stu[count].name;
        cout <<"Enter the " << count + 1 << " student' scores in order" << endl;
        cin >> Stu[count].score1 >> Stu[count].score2 >> Stu[count].score3;
        Stu[count].average = (Stu[count].score1 + Stu[count].score2 + Stu[count].score3)/3; //计算平均成绩
        Cou[0].get(Stu[count], 1); Cou[1].get(Stu[count], 2); Cou[2].get(Stu[count], 3);    //计算科目的最大最小值，并统计总和
        count++;
    }
    count = 0;
    //开始输出结果
    cout << "no\tname\tscore1\tscore2\tscore3\taverage\t" << endl;
    //以此输出学生的序号、姓名、科目成绩
    while( count < 10){
        cout << count + 1 << "\t ";
        cout <<Stu[count].name << "\t";
        cout <<Stu[count].score1 << "\t";
        cout << Stu[count].score2 << "\t";
        cout << Stu[count].score3 << "\t";
        cout << Stu[count].average << "\t" << endl;
        count++;
    }
    //以此输出每个学科的平均数、最大值、最小值
    cout << "\t" << "average\t " << Cou[0].sum/10 << "\t" << Cou[1].sum/10 << "\t" << Cou[2].sum/10 << endl;
    cout << "\t" << "min\t " << Cou[0].min << "\t" << Cou[1].min << "\t" << Cou[2].min << "\t" << endl;
    cout << "\t" << "max\t " << Cou[0].max << "\t" << Cou[1].max << "\t" << Cou[2].max << "\t" << endl;
    return 0;
}