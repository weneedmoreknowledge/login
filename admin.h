//
//  admin.h
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#ifndef admin_h
#define admin_h
#include <fstream>
#include <iostream>
#include "setInfo.h"
using namespace std;
void search(Student st[],Teacher te[],User us[]);
void addStu(Student st[],User us[]);
void addTea(Teacher st[],User us[]);
void delStu(Student st[]);
void delTea(Teacher st[]);

#endif /* admin_h */
