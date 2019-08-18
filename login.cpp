//
//  login.cpp
//  assignment
//
//  Created by KANG MINWOO on 8/11/19.
//  Copyright © 2019 KANG MINWOO. All rights reserved.
//

#include "login.h"

string tID;
string tPass;

void change_pass(User us[],string ID){
    string cPass;
    cout<<"Enter the new Password : ";
    for (int i=0; i<1000; i++) {
        if (ID==us[i].ID) {
            cin>>cPass;
            us[i].Pass=cPass;
            break;
        }
    }
}

void login(Student st[],Teacher te[],User us[],Course co[]){
    cout<<"ID : ";
    cin>>tID;
    int count=0;
    while (tID!=us[count].ID) {
        count++;
        if (count==2000) {
            cout<<"Sorry, we cannot find the ID. Try again.";
            cin>>tID;
            count=0;
        }
    }//while end
    for (int i=0; i<1000; i++) {
        if (us[i].ID==""||us[i].Pass==""){
            break;
        }
        else if (tID==us[i].ID) {
            cout<<"Password : ";
            cin>>tPass;
            if (tPass!=us[i].Pass) {
                cout<<"Try again. It is not correct Pass.\n";
                cin>>tPass;
            }
            else{
                //admin
                if(tID==us[0].ID&&tPass==us[0].Pass){
                
                cout<<"This is admin account.\n";
                int cho1=0;
                cout<<"What do you want to do?\n";
                cout<<"1.Change Password. 2.Add student. 3.Add Teacher. 4.Delete student. 5.Delete Teacher. 6.Search. 7.Log Out.\n";
                cin>>cho1;
                switch (cho1) {
                    case 1:{
                        change_pass(us,tID);
                        break;
                    }
                    case 2:{
                        addStu(st, us);
                        break;
                    }
                    case 3:{
                        addTea(te, us);
                        break;
                    }
                    case 4:{
                        delStu(st);
                        break;
                    }
                    case 5:{
                        delTea(te);
                        break;
                    }
                    case 6:{
                        search(st,te,us);
                        break;
                    }
                    case 7:{
                        login(st,te,us,co);
                        break;
                    }
                    default:{
                        cin>>cho1;
                    }
                }
                    
                }
                //teacher
                else if (tID==us[i].ID&&us[i].Position=="teacher"){
                    
                cout<<"This is teacher account.\n";
                int cho2=0;
                cout<<"What do you want to do?\n";
                cout<<"1.Change Password. 2.Open Course. 3.Sumerize Score. 4.Modify score 5.Log Out.\n";
                cin>>cho2;
                switch (cho2) {
                    case 1:{
                        change_pass(us,tID);
                        break;
                    }
                    case 2:{
                        open_course(co);
                        break;
                    }
                    case 3:{
                        Teacher pTe1;
                        for (int k=0; k<1000; k++) {
                            if(tID==te[k].ID){
                                pTe1.ID=te[k].ID;
                                pTe1.Name=te[k].Name;
                                pTe1.Birth=te[k].Birth;
                                pTe1.Adress=te[k].Adress;
                                pTe1.course=te[k].course;
                                pTe1.Phone=te[k].Phone;
                                break;
                            }
                        }
                        summarize(st, pTe1);
                        break;
                    }
                    case 4:{
                        Teacher pTe2;
                        for (int k=0; k<1000; k++) {
                            if(tID==te[k].ID){
                                pTe2.ID=te[k].ID;
                                pTe2.Name=te[k].Name;
                                pTe2.Birth=te[k].Birth;
                                pTe2.Adress=te[k].Adress;
                                pTe2.course=te[k].course;
                                pTe2.Phone=te[k].Phone;
                                break;
                            }
                        }
                        modify(st,pTe2);
                        break;
                    }
                    case 5:{
                        login(st,te,us,co);
                        break;
                    }
                    default:{
                        cin>>cho2;
                    }
                }
            
                }
                //student
            else if (tID==us[i].ID&&tPass==us[i].Pass&&us[i].Position=="student"){
                cout<<"This is student account.\n";
                int cho3=0;
                cout<<"What do you want to do?\n";
                cout<<"1.Change Password. 2.Register Course. 3.Delete Course. 4.View Profile. 5.Log Out.\n";
                cin>>cho3;
                switch (cho3) {
                    case 1:{
                        change_pass(us,tID);
                        break;
                    }
                    case 2:{
                        Student pSt1;
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                pSt1.ID=st[k].ID;
                                pSt1.Name=st[k].Name;
                                pSt1.Birth=st[k].Birth;
                                pSt1.Adress=st[k].Adress;
                                for (int p=0; p<20; p++) {
                                    pSt1.sCo[p].CCO=st[k].sCo[p].CCO;
                                    pSt1.sCo[p].Code=st[k].sCo[p].Code;
                                    pSt1.sCo[p].Name=st[k].sCo[p].Name;
                                    pSt1.sCo[p].Credit=st[k].sCo[p].Credit;
                                    pSt1.sCo[p].Lecture=st[k].sCo[p].Lecture;
                                    pSt1.sCo[p].score=st[k].sCo[p].score;
                                }
                            }
                        }
                        Regi(co, pSt1);
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                st[k].ID=pSt1.ID;
                                st[k].Name=pSt1.Name;
                                st[k].Birth=pSt1.Birth;
                                st[k].Adress=pSt1.Adress;
                                for (int p=0; p<20; p++) {
                                    st[k].sCo[p].CCO=pSt1.sCo[p].CCO;
                                    st[k].sCo[p].Code=pSt1.sCo[p].Code;
                                    st[k].sCo[p].Name=pSt1.sCo[p].Name;
                                    st[k].sCo[p].Credit=pSt1.sCo[p].Credit;
                                    st[k].sCo[p].Lecture=pSt1.sCo[p].Lecture;
                                    st[k].sCo[p].score=pSt1.sCo[p].score;
                                }
                            }
                        }
                        for (int k=0; k<1000; k++) {
                            if(tID==st[k].ID){
                                int crd=0;
                                for (int j=0; j<20; j++) {
                                crd+=st[k].sCo[j].Credit_n;
                                }
                                if (crd>20) {
                                    cout<<"Warning, you are able to take courses under 20 credits."<<endl;
                                    cout<<"You should delete some courses, or you cannot take a class.\n";
                                }
                            }
                        }
                        break;
                    }
                    case 3:{
                        Student pSt2;
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                pSt2.ID=st[k].ID;
                                pSt2.Name=st[k].Name;
                                pSt2.Birth=st[k].Birth;
                                pSt2.Adress=st[k].Adress;
                                for (int p=0; p<20; p++) {
                                    pSt2.sCo[p].CCO=st[k].sCo[p].CCO;
                                    pSt2.sCo[p].Code=st[k].sCo[p].Code;
                                    pSt2.sCo[p].Name=st[k].sCo[p].Name;
                                    pSt2.sCo[p].Credit=st[k].sCo[p].Credit;
                                    pSt2.sCo[p].Lecture=st[k].sCo[p].Lecture;
                                    pSt2.sCo[p].score=st[k].sCo[p].score;
                                }
                            }
                        }
                        Del_co(co, pSt2);
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                st[k].ID=pSt2.ID;
                                st[k].Name=pSt2.Name;
                                st[k].Birth=pSt2.Birth;
                                st[k].Adress=pSt2.Adress;
                                for (int p=0; p<20; p++) {
                                    st[k].sCo[p].CCO=pSt2.sCo[p].CCO;
                                    st[k].sCo[p].Code=pSt2.sCo[p].Code;
                                    st[k].sCo[p].Name=pSt2.sCo[p].Name;
                                    st[k].sCo[p].Credit=pSt2.sCo[p].Credit;
                                    st[k].sCo[p].Lecture=pSt2.sCo[p].Lecture;
                                    st[k].sCo[p].score=pSt2.sCo[p].score;
                                }
                            }
                        }
                        break;
                    }
                    case 4:{
                        Student pSt3;
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                pSt3.ID=st[k].ID;
                                pSt3.Name=st[k].Name;
                                pSt3.Birth=st[k].Birth;
                                pSt3.Adress=st[k].Adress;
                                for (int p=0; p<20; p++) {
                                    pSt3.sCo[p].CCO=st[k].sCo[p].CCO;
                                    pSt3.sCo[p].Code=st[k].sCo[p].Code;
                                    pSt3.sCo[p].Name=st[k].sCo[p].Name;
                                    pSt3.sCo[p].Credit=st[k].sCo[p].Credit;
                                    pSt3.sCo[p].Lecture=st[k].sCo[p].Lecture;
                                    pSt3.sCo[p].score=st[k].sCo[p].score;
                                }
                            }
                        }
                        View(pSt3);
                        for (int k=0; k<1000; k++) {
                            if (tID==st[k].ID) {
                                st[k].ID=pSt3.ID;
                                st[k].Name=pSt3.Name;
                                st[k].Birth=pSt3.Birth;
                                st[k].Adress=pSt3.Adress;
                                for (int p=0; p<20; p++) {
                                    st[k].sCo[p].CCO=pSt3.sCo[p].CCO;
                                    st[k].sCo[p].Code=pSt3.sCo[p].Code;
                                    st[k].sCo[p].Name=pSt3.sCo[p].Name;
                                    st[k].sCo[p].Credit=pSt3.sCo[p].Credit;
                                    st[k].sCo[p].Lecture=pSt3.sCo[p].Lecture;
                                    st[k].sCo[p].score=pSt3.sCo[p].score;
                                }
                            }
                        }
                        break;
                    }//view end
                    case 5:{
                        login(st,te,us,co);
                        break;
                    }
                    default:{
                        cin>>cho3;
                    }
                }//switch end
            }//else stu end
        }
    }
} //for end
    
    //update
    ofstream file;
    file.open("student.csv");
    for (int i=0; i<1000; i++) {
        if(st[i].ID==""||st[i].Name==""){
            break;
        }
        file<<st[i].ID<<','<<st[i].Name<<','<<st[i].Birth<<','<<'\"'<<st[i].Adress<<'\"'<<'\r'<<'\n';
    }
    file.close();
    
    ofstream file2;
    file2.open("teacher.csv");
    for (int i=0; i<1000; i++) {
        if(te[i].ID==""||te[i].Name==""){
            break;
        }
        file2<<te[i].ID<<','<<te[i].Name<<','<<te[i].Birth<<'\"'<<te[i].Phone<<'\"'<<'\"'<<te[i].Adress<<'\"'<<'\r'<<'\n';
    }
    file2.close();
    
    ofstream file3;
    file3.open("user.csv");
    for (int i=0; i<1000; i++) {
        if(us[i].ID==""||us[i].Pass==""){
            break;
        }
        else if(us[i].ID==us[i-1].ID)
        {
            for(int j=i;j<1000;j++){
            us[j].ID="";
            us[j].Pass="";
            us[j].Position="";
            }
        }
        file3<<us[i].ID<<','<<us[i].Pass<<','<<us[i].Position<<'\r'<<'\n';
    }
    
    ofstream file4;
    file4.open("grade.csv");
    for (int i=0;i<1000; i++) {
        for (int j=0;j<20; j++) {
            if(st[i].sCo[j].CCO==""&&st[i].ID==""&&st[i].sCo[j].Code==""&&st[i].sCo[j].score==""&&st[i].semester==""){
                break;
            } file4<<st[i].sCo[j].CCO<<','<<st[i].ID<<','<<st[i].sCo[j].Code<<','<<st[i].sCo[j].score<<','<<st[i].semester<<'\r'<<'\n';
        }
    }
    //update end
}//end login
