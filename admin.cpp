//
//  admin.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include "admin.h"
using namespace std;

void search(Student st[],Teacher te[],User us[]){
    int cho=0;
    string pID;
    string pName;
    cout<<"Which type you want to find? \n 1. ID \t 2. Name \n";
    cin>>cho;
    switch (cho) {
        case 1:{
            cout<<"Enter the ID : ";
            cin>>pID;
            for (int i=0; i<1000; i++) {
                if (pID==st[i].ID) {
                    cout<<st[i].ID<<endl;
                    cout<<st[i].Name<<endl;
                    cout<<st[i].Birth<<endl;
                    cout<<st[i].Adress<<endl;
                    for (int j=0; j<20; j++) {
                        cout<<"CCO : "<<st[i].sCo[j].CCO<<endl;
                        cout<<"Code : "<<st[i].sCo[j].Code<<endl;
                        cout<<"Name : "<<st[i].sCo[j].Name<<endl;
                        cout<<"Credit : "<<st[i].sCo[j].Credit<<endl;
                        cout<<"Lectuer : "<<st[i].sCo[j].Lecture<<endl;
                    }
                }
                else if (pID==te[i].ID) {
                    cout<<te[i].ID<<endl;
                    cout<<te[i].Name<<endl;
                    cout<<te[i].Birth<<endl;
                    cout<<te[i].Phone<<endl;
                    cout<<te[i].Adress<<endl;
                    //cout<<st[i].course<<endl;
                }
            }
            break;
        }
        case 2:{
            cout<<"Enter the Name : ";
            cin>>pName;
            for (int i=0; i<1000; i++) {
                if (pName==st[i].Name) {
                    cout<<st[i].ID<<endl;
                    cout<<st[i].Name<<endl;
                    cout<<st[i].Birth<<endl;
                    cout<<st[i].Adress<<endl;
                    //cout<<st[i].course<<endl;
                    break;
                }
                else if (pName==te[i].Name) {
                    cout<<te[i].ID<<endl;
                    cout<<te[i].Name<<endl;
                    cout<<te[i].Birth<<endl;
                    cout<<te[i].Adress<<endl;
                    //cout<<st[i].course<<endl;
                    break;
                }
            }
            break;
        }
        default:{
            cout<<"Enter again.\n";
            cin>>cho;
        }
    }
}

void addStu(Student st[],User us[]){
    string nID,nName,nBirth,nAdress,nBlank;
    for (int i=0; i<1000; i++) {
        if (st[i].ID==""||st[i].Name==""||st[i].Birth==""||st[i].Adress=="") {
            cout<<"Enter the information of Student.\nID : ";
            getline(cin,nBlank);
            getline(cin,nID);
            cout<<"Name : ";
            getline(cin,nName);
            cout<<"Birth date : ";
            getline(cin,nBirth);
            cout<<"Adress : ";
            getline(cin,nAdress);
            st[i].ID=nID;
            st[i].Name=nName;
            st[i].Birth=nBirth;
            st[i].Adress=nAdress;
            break;
        }
    }
    for (int i=0; i<1000; i++) {
        if (us[i].ID==""||us[i].Pass==""||us[i].Position==""){
            us[i].ID=nID;
            us[i].Pass=nID;
            us[i].Position="student";
            break;
        }
    }
}

void addTea(Teacher st[],User us[]){
    string nID,nName,nBirth,nAdress,nPhone,nBlank;
    for (int i=0; i<1000; i++) {
        if (st[i].ID==""||st[i].Name==""||st[i].Birth==""||st[i].Adress=="") {
            cout<<"Enter the information of Student.\nID : ";
            getline(cin,nBlank);
            getline(cin,nID);
            cout<<"Name : ";
            getline(cin,nName);
            cout<<"Birth date : ";
            getline(cin,nBirth);
            cout<<"Phone number : ";
            getline(cin,nPhone);
            cout<<"Adress : ";
            getline(cin,nAdress);
            st[i].ID=nID;
            st[i].Name=nName;
            st[i].Birth=nBirth;
            st[i].Phone=nPhone;
            st[i].Adress=nAdress;
            break;
        }
    }
    for (int i=0; i<1000; i++) {
        if (us[i].ID==""||us[i].Pass==""||us[i].Position==""){
            us[i].ID=nID;
            us[i].Pass=nID;
            us[i].Position="teacher";
        }
    }
}

void delStu(Student st[]){
    int cho;
    string pID;
    string pName;
    string nBlank;
    cout<<"Which type do you want?"<<endl;
    cout<<"1. ID\t2. Name\n";
    cin>>cho;
    switch (cho) {
        case 1:{
            cout<<"Enter the ID : ";
            cin>>pID;
            for (int i=0; i<1000; i++) {
                if (pID==st[i].ID) {
                    st[i].ID="";
                    st[i].Name="";
                    st[i].Birth="";
                    st[i].Adress="";
                    for (int j=i; j<1000; j++) {
                        st[j].ID=st[j+1].ID;
                        st[j].Name=st[j+1].Name;
                        st[j].Birth=st[j+1].Birth;
                        st[j].Adress=st[j+1].Adress;
                    }
                }
            }
            break;
        }
        case 2:{
            cout<<"Enter the Name : ";
            getline(cin,nBlank);
            getline(cin,pName);
            for (int i=0; i<1000; i++) {
                if (pName==st[i].Name) {
                    st[i].ID="";
                    st[i].Name="";
                    st[i].Birth="";
                    st[i].Adress="";
                    for (int j=i; j<1000; j++) {
                        st[j].ID=st[j+1].ID;
                        st[j].Name=st[j+1].Name;
                        st[j].Birth=st[j+1].Birth;
                        st[j].Adress=st[j+1].Adress;
                    }
                }
            }
            break;
        }
        default:{cin>>cho;}
    }
}

void delTea(Teacher st[]){
    int cho;
    string pID;
    string pName;
    string nBlank;
    cout<<"Which type do you want?"<<endl;
    cout<<"1. ID\t2. Name\n";
    cin>>cho;
    switch (cho) {
        case 1:{
            cout<<"Enter the ID : ";
            cin>>pID;
            for (int i=0; i<1000; i++) {
                if (pID==st[i].ID) {
                    st[i].ID="";
                    st[i].Name="";
                    st[i].Birth="";
                    st[i].Adress="";
                    for (int j=i; j<1000; j++) {
                        st[j].ID=st[j+1].ID;
                        st[j].Name=st[j+1].Name;
                        st[j].Birth=st[j+1].Birth;
                        st[j].Adress=st[j+1].Adress;
                    }
                }
            }
            break;
        }
        case 2:{
            cout<<"Enter the Name : ";
            getline(cin,nBlank);
            getline(cin,pName);
            for (int i=0; i<1000; i++) {
                if (pName==st[i].Name) {
                    st[i].ID="";
                    st[i].Name="";
                    st[i].Birth="";
                    st[i].Adress="";
                    for (int j=i; j<1000; j++) {
                        st[j].ID=st[j+1].ID;
                        st[j].Name=st[j+1].Name;
                        st[j].Birth=st[j+1].Birth;
                        st[j].Adress=st[j+1].Adress;
                    }
                }
            }
            break;
        }
        default:{cin>>cho;}
    }
}
