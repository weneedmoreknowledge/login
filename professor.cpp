//
//  professor.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/13/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "setInfo.h"

using namespace std;

void open_course(Course co[]){
    for (int i=0; i<50; i++) {
        if (co[i].CCO=="") {
            break;
        }
        cout<<i<<endl;
        cout<<co[i].CCO<<","<<co[i].Name<<","<<co[i].Credit<<","<<co[i].Lecture<<"\n\n";
    }
}

void summarize(Student st[],Teacher te){
    for (int i=0; i<1000; i++) {
        for (int j=0; j<20; j++) {
            if (st[i].sCo[j].Name==te.course) {
                cout<<endl;
                cout<<"ID : "<<st[i].ID<<endl;
                cout<<"Name : "<<st[i].Name<<endl;
                cout<<"Score : "<<st[i].sCo[j].score<<endl;
                cout<<endl;
            }
        }
    }
}

void modify(Student st[],Teacher te){
    string pID;
    string pName;
    int cho;
    cout<<"Which type do you want to find?\n1. ID   2. Name\n";
    cin>>cho;
    switch (cho) {
        case 1:{
            cout<<"Enter the ID : ";
            cin>>pID;
            for (int i=0; i<1000; i++) {
            if (pID==st[i].ID) {
                for (int j=0; j<20; j++) {
                    if (st[i].sCo[j].Name==te.course) {
                        cin>>st[i].sCo[j].score;
                        }
                    }
                }
            }
            break;
        }
        case 2:{
            cout<<"Enter the Name : ";
            cin>>pName;
            for (int i=0; i<1000; i++) {
            if (pName==st[i].Name) {
                for (int j=0; j<20; j++) {
                    if (st[i].sCo[j].Name==te.course) {
                            cin>>st[i].sCo[j].score;
                        }
                    }
                }
            }
            break;
        }
        default:
            cin>>cho;
    }
}
