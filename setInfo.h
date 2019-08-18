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
#include "setInfo.cpp"

using namespace std;

void set_Student(Student st[]);
void set_Teacher(Teacher st[]);
void set_User(User us[]);
void set_Course(Course co[],Teacher te[]);
void convert(Student st[]);

#endif /* setInfo_h */
