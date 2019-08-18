//
//  professor.h
//  assignment
//
//  Created by KANG MINWOO on 8/13/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#ifndef professor_h
#define professor_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "setInfo.h"

using namespace std;

void open_course(Course co[]);
void summarize(Student st[],Teacher te);
void modify(Student st[],Teacher te);


#endif /* professor_h */
