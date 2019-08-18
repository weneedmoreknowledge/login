//
//  setInfo.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include "setInfo.h"

void set_Student(Student *st){
    ifstream file("student.csv");
    if(!file.is_open()){
        cout<<"Error! We cannot load the student database!";
        exit(EXIT_FAILURE);
    }
    int count=0;
    while (!file.eof())
    {
        string temp_id;
        string temp_name;
        string temp_birth;
        string temp_adress;
        string temp_blank;
        getline(file,temp_id,',');
        getline(file,temp_name,',');
        getline(file,temp_birth,',');
        getline(file,temp_blank,'\"');
        getline(file,temp_adress,'\"');
        getline(file,temp_blank,'\n');
        st[count].ID=temp_id;
        st[count].Name=temp_name;
        st[count].Birth=temp_birth;
        st[count].Adress=temp_adress;
        count++;
    }
    file.close();
    ifstream file2("grade.csv");
    if (!file2.is_open()) {
        cout<<"Error! We cannot load the grade database!";
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<1000;i++) {
        string temp_CCO;
        string temp_stuID;
        string temp_Code;
        string temp_score;
        string temp_sem;
        string blank;
        getline(file2, temp_CCO, ',');
        getline(file2, temp_stuID, ',');
        getline(file2, temp_Code,',');
        getline(file2, temp_score, ',');
        getline(file2, temp_sem,'\r');
        getline(file2, blank, '\n');
        for (int j=0;j<20; j++) {
            if (st[i].ID==temp_stuID){
                st[i].sCo[j].CCO=temp_CCO;
                st[i].sCo[j].Code=temp_Code;
                st[i].sCo[j].score=temp_score;
                st[i].semester=temp_sem;
            }
        }
    }
}

void set_Teacher(Teacher *st){
    ifstream file("teacher.csv");
    if(!file.is_open()){
        cout<<"Error! We cannot load the teacher database!";
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<1000; i++) {
        string temp_blank;
        getline(file, st[i].ID, ',');
        getline(file, st[i].Name, ',');
        getline(file, st[i].Birth, ',');
        getline(file, temp_blank,'\"');
        getline(file, st[i].Phone, '\"');
        getline(file, temp_blank, '\"');
        getline(file, st[i].Adress,'\"');
        getline(file, temp_blank,'\n');
    }
    file.close();
}

void set_User(User *us){
    ifstream file("user.csv");
    if(!file.is_open()){
        cout<<"Error! We cannot load the user database!";
        exit(EXIT_FAILURE);
    }
    int count=0;
    while (!file.eof()) {
        string temp_id;
        string temp_pass;
        string temp_posi;
        string temp_blank;
        getline(file, temp_id, ',');
        getline(file, temp_pass, ',');
        getline(file, temp_posi, '\r');
        getline(file, temp_blank, '\n');
        us[count].ID=temp_id;
        us[count].Pass=temp_pass;
        us[count].Position=temp_posi;
        count++;
    }
    file.close();
}

void set_Course(Course *co,Teacher *te){
    ifstream file("course.csv");
    if (!file.is_open()) {
        cout<<"Error! We cannot load the course database!";
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<50; i++) {
        string temp_blank;
        getline(file, co[i].CCO, ',');
        getline(file, co[i].Code, ',');
        getline(file, co[i].Name, ',');
        getline(file, co[i].Credit,',');
        getline(file, co[i].Lecture, '\r');
        getline(file, temp_blank, '\n');
    }
    file.close();
    
    for (int j=0; j<1000; j++) {
        for (int k=0; k<1000; k++) {
            if (te[j].ID==co[k].Code) {
                te[j].course=co[k].Name;
            }
        }
    }
    for (int i=0; i<1000; i++) {
        if (co[i].Credit=="1")
            co[i].Credit_n=1;
        else if (co[i].Credit=="2")
            co[i].Credit_n=2;
        else if (co[i].Credit=="3")
            co[i].Credit_n=3;
        else if (co[i].Credit=="4")
            co[i].Credit_n=4;
        else if (co[i].Credit=="5")
            co[i].Credit_n=5;
        else if (co[i].Credit=="6")
            co[i].Credit_n=6;
        else if (co[i].Credit=="7")
            co[i].Credit_n=7;
        else if (co[i].Credit=="8")
            co[i].Credit_n=8;
        else if (co[i].Credit=="9")
            co[i].Credit_n=9;
        else
            co[i].Credit_n=0;
    }
}

void convert(Student *st){
    for (int i=0; i<1000; i++) {
        for (int j=0; j<20; j++) {
                if (st[i].sCo[j].Credit=="1")
                    st[i].sCo[j].Credit_n=1;
                else if (st[i].sCo[j].Credit=="2")
                    st[i].sCo[j].Credit_n=2;
                else if (st[i].sCo[j].Credit=="3")
                    st[i].sCo[j].Credit_n=3;
                else if (st[i].sCo[j].Credit=="4")
                    st[i].sCo[j].Credit_n=4;
                else if (st[i].sCo[j].Credit=="5")
                    st[i].sCo[j].Credit_n=5;
                else if (st[i].sCo[j].Credit=="6")
                    st[i].sCo[j].Credit_n=6;
                else if (st[i].sCo[j].Credit=="7")
                    st[i].sCo[j].Credit_n=7;
                else if (st[i].sCo[j].Credit=="8")
                    st[i].sCo[j].Credit_n=8;
                else if (st[i].sCo[j].Credit=="9")
                    st[i].sCo[j].Credit_n=9;
                else
                    st[i].sCo[j].Credit_n=0;
        }
    }
}
