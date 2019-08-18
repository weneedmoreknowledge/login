//
//  main.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "setInfo.h"
#include "admin.h"
#include "professor.h"
#include "student.h"
#include "login.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Student st[1000];
    Teacher te[1000];
    User us[2000];
    Course co[1000];
    set_Student(st);
    set_Teacher(te);
    set_User(us);
    set_Course(co,te);
    convert(st);
    
    login(st, te, us, co);
    
    system("pause");
    return 0;
}
