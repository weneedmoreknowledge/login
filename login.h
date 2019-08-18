//
//  login.h
//  assignment
//
//  Created by KANG MINWOO on 8/13/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#ifndef login_h
#define login_h
#include <iostream>
#include <fstream>
#include "admin.h"
#include "professor.h"
#include "student.h"
using namespace std;

void change_pass(User *us,string ID);
void login(Student *st,Teacher *te,User *us,Course *co);

#endif /* login_h */
