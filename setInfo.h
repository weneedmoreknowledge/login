//
//  setInfo.h
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#ifndef setInfo_h
#define setInfo_h
#include <iostream>
#include <fstream>
using namespace std;

struct Course{
    string CCO;
    string Name;
    string Credit;
    int Credit_n;
    string Lecture;
    string Code;
    string score;
};

struct Student {
    string ID;
    string Name;
    string Birth;
    string Adress;
    string semester;
    Course sCo[20];
};

struct Teacher {
    string ID,Name,Birth,Phone,Adress,course;
};

struct User {
    string ID,Pass,Position;
};

void set_Student(Student st[]);
void set_Teacher(Teacher st[]);
void set_User(User us[]);
void set_Course(Course co[],Teacher te[]);
void convert(Student st[]);

#endif /* setInfo_h */
