//
//  student.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/13/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include "student.h"

void Regi(Course *co,Student st){
    for (int i=0; i<20; i++) {
        if (co[i].CCO==""||co[i].Code==""||co[i].Name=="") {
            break;
        } cout<<co[i].CCO<<","<<co[i].Code<<","<<co[i].Name<<","<<co[i].Credit<<","<<co[i].Lecture<<endl;
    }
    string pCode;
    cout<<"Which course do you want to take (CCO)?"<<endl;
    cin>>pCode;
    for (int i=0; i<100; i++) {
        if (co[i].CCO==pCode) {
            for (int j=0; j<20; j++) {
                if(st.sCo[j].CCO==""||st.sCo[j].Code==""||st.sCo[j].Name==""){
                    st.sCo[j].CCO=co[i].CCO;
                    st.sCo[j].Code=co[i].Code;
                    st.sCo[j].Name=co[i].Name;
                    st.sCo[j].Credit=co[i].Credit;
                    st.sCo[j].Lecture=co[i].Lecture;
                    st.sCo[j].score="0";
                    break;
                }
            }
        }
    }
}

void Del_co(Course *co,Student st){
    for (int i=0; i<20; i++) {
        cout<<st.sCo[i].CCO<<","<<st.sCo[i].Code<<","<<st.sCo[i].Name<<","<<st.sCo[i].Credit<<","<<st.sCo[i].Lecture<<","<<st.sCo[i].score<<endl;
    }
    string pCode;
    cout<<"Which course do you want to remove (Code)?"<<endl;
    cin>>pCode;
    for (int i=0; i<100; i++) {
        if (st.sCo[i].Code==pCode) {
            st.sCo[i].CCO="";
            st.sCo[i].Code="";
            st.sCo[i].Name="";
            st.sCo[i].Credit="";
            st.sCo[i].Lecture="";
            st.sCo[i].score="";
            for (int j=i; j<20; j++) {
                st.sCo[j].CCO=st.sCo[j+1].CCO;
                st.sCo[j].Code=st.sCo[j+1].Code;
                st.sCo[j].Name=st.sCo[j+1].Name;
                st.sCo[j].Credit=st.sCo[j+1].Credit;
                st.sCo[j].Lecture=st.sCo[j+1].Lecture;
                st.sCo[j].score=st.sCo[j+1].score;
            }
        }
    }
}

void View(Student st){
    cout<<"ID : "<<st.ID<<endl;
    cout<<"Name : "<<st.Name<<endl;
    cout<<"Birth : "<<st.Birth<<endl;
    cout<<"Adress : "<<st.Adress<<endl;
    cout<<"Registed Courses : "<<endl;
    for (int i=0; i<20; i++) {
        cout<<st.sCo[i].CCO<<","<<st.sCo[i].Code<<","<<st.sCo[i].Name<<","<<st.sCo[i].Credit<<","<<st.sCo[i].Lecture<<endl;
    }
}
