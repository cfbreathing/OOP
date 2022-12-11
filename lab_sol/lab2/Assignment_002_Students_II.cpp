/*
    本程序实现了CLI操作和不定项输入输出
    录入信息时，先输入某同学姓名，接着按下空格，开始录入成绩信息
    每门成绩的名称和成绩用空格区隔开
    录完一名同学成绩后，按下回车即可开始记录下位同学信息
    录完所有同学信息后，输入一个空行可以终止输入，此时终端会输出所有同学的信息

*/
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX_NAME_LEN 20
#define MAX_COURSE_NUM 10000
#define AVE_ 0
#define MIN_ 1
#define MAX_ 2
// debug用，需要时取消注释即可
// #define DEBUG 

struct Course{
    string courseName;
    int score;
};

class Student{
private:
    string name;
    int num;
    float average;
    vector<Course> courses;

public:
    vector<Course> getCourses();
    void setGrades(string cN, int cS);
    void calcAverage();
    void printGrades();
    Student(string, int);
};

void printStat(const vector<Student*> stu);
void calcStat(const vector<Student*> stuRecords, float stat[][MAX_COURSE_NUM]);

vector<string> courseList; 

int main(){
    int isInList, i;
    int stuCnt = 0;
    vector<Student*> stu;
    cout << "Welcome to use students information system." << endl;
    while(true){
        string input, name;
        name.resize(MAX_NAME_LEN);
        getline(cin, input);
        if(input.size() == 0) break;
        input.append(1, '\0');

        #ifdef DEBUG
        cout << input << endl;
        #endif

        int t = 0;
        while(input[t] != ' '){name[t] = input[t]; t++;}

        #ifdef DEBUG
        cout << "name = " << name << endl;
        #endif

        Student *stuRecord = new Student(name, ++stuCnt);
        while(input[t] != '\0'){
            string courseName = "";
            courseName.resize(MAX_NAME_LEN);
            int i = 0;
            while(input[t] == ' ') t++;
            while(input[t] != ' '){courseName[i] = input[t]; t++; i++;}
            courseName[i] = '\0';

            #ifdef DEBUG
            cout << "courseName=" << courseName << endl;
            #endif

            int courseScore = 0;
            while(input[t] == ' ') t++;
            while(input[t] != ' ' && input[t] != '\0'){courseScore = courseScore * 10 + atoi(input.substr(t, 1).c_str()); t++;}

            #ifdef DEBUG
            cout << "courseScore = " << courseScore << endl;
            #endif

            stuRecord->setGrades(courseName, courseScore);
            for(i = 0, isInList = false; i < courseList.size(); i++)
                if(courseList[i] == courseName){
                    isInList = true;
                    break;
                }
            if(!isInList)
                courseList.push_back(courseName);        
        }
        stu.push_back(stuRecord);
    }
    // 输出表头
    cout << "no\t" << "name\t";
    for(int i = 0; i < courseList.size(); i++)
        cout << courseList[i] << "\t";
    cout << "average\t" << endl;
    // 依次输出学生成绩
    for(int i = 0; i < stu.size(); i++){
        stu[i]->calcAverage();
        stu[i]->printGrades();
    }
    // 输出成绩的最大值、最小值和平均值
    printStat(stu);
    system("Pause"); 
    return 0;
}

Student::Student(string stuName, int stuNum){
    name = stuName;
    num = stuNum;
}

vector<Course> Student::getCourses(){
    return courses;
}


void Student::setGrades(string courseName, int courseScore){
    // 设置学生的成绩
    Course courseRecord;
    courseRecord.courseName = courseName;
    courseRecord.score= courseScore;
    courses.push_back(courseRecord);
}

void Student::calcAverage(){
    // 计算成绩的平均数
    float sum = 0;
    for(int i = 0; i < courses.size(); i++)
        sum += courses[i].score;
    average = sum / courses.size();
}

void Student::printGrades(){
    // 依次输出每个同学的成绩
	int i, j, isStudied;
    cout << num << "\t" << name << "\t";
    for(i = 0; i < courseList.size(); i++){
        for(j = 0, isStudied = 0; j < courses.size(); j++)
            // 当某门课同学有学时，则输出
            if(courses[j].courseName == courseList[i]){
                cout << courses[j].score << "\t";
                isStudied = 1;
                break;
            }
            //如果该同学没有学这门课，则不输出
        if(!isStudied)
            cout << "\t";
    }
    cout << average << endl;
}

void printStat(const vector<Student*> stuRecords){
    float stat[3][MAX_COURSE_NUM];
    calcStat(stuRecords, stat);
    // 输出课程信息
    // 输出平均分
    cout << "\t" << "average\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< fixed << setprecision(1) << stat[AVE_][i] << "\t";
    cout << endl;
    // 输出最低分
    cout << "\t" << "min\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< stat[MIN_][i] << "\t";
    cout << endl;
    // 输出最高分
    cout << "\t" << "max\t";
    for(int i = 0; i < courseList.size(); i++)
        cout<< stat[MAX_][i] << "\t";
    cout << endl;
}

void calcStat(const vector<Student*> stuRecords, float stat[][MAX_COURSE_NUM]){
    // 统计课程信息
    vector<Course> stuCourses;
    int cnt;
    // 初始化课程信息
    for(int i = 0; i < courseList.size(); i++){
        stat[AVE_][i] = 0;
        stat[MAX_][i] = 0;
        stat[MIN_][i] = 101;
        cnt = 0;
        for(int j = 0; j < stuRecords.size(); j++){
            stuCourses = stuRecords[j]->getCourses();
            // 检索某同学是否上了这门课
            for(int k = 0; k < stuCourses.size(); k++){
                if(stuCourses[k].courseName == courseList[i]){
                    stat[AVE_][i] += stuCourses[k].score;
                    stat[MAX_][i] = stat[MAX_][i] < stuCourses[k].score ? stuCourses[k].score : stat[MAX_][i];
                    stat[MIN_][i] = stat[MIN_][i] > stuCourses[k].score ? stuCourses[k].score : stat[MIN_][i];
                    cnt ++;
                }
            }
        }
        stat[AVE_][i] /= cnt;
    }
}