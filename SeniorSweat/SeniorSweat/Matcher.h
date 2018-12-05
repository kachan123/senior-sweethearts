//
//  Matcher.h
//  SeniorSweat
//
//  Created by Roberto D'angelo-Cosme on 11/23/18.
//  Copyright © 2018 Roberto D'angelo-Cosme. All rights reserved.
//

#ifndef Matcher_h
#define Matcher_h
#include "UserList.h"
#include <fstream>
using namespace std;

class Matcher{
public:
    Matcher();
    Matcher(UserList*);
    
    void Match();
    void FinalizeAndExport();
    
private:
    UserList* ListProcess;
};

Matcher::Matcher(){
    ListProcess=NULL;
}

Matcher::Matcher(UserList*p){ //two copies of the list
    ListProcess=p;
}
void Matcher::Match(){
    if(ListProcess->head==NULL){
        cout<<"tis null"<<endl;
        return;
    }
    User*temp=ListProcess->head;
    User*temp2=temp->next;
    while(temp!=NULL){
        if(temp2==NULL){
            return;
        }
        while(temp2!=NULL){
            for(int i=0; i<temp->Choices.size();i++){
                for(int j=0; j<temp2->Choices.size();j++){
                    if((temp->Choices[i]==temp2->NETID&&temp2->Choices[j]==temp->NETID)){
                        temp->Matches.push_back(temp2->NETID);
                        temp2->Matches.push_back(temp->NETID);
                    }
                }
            }
            temp2=temp2->next;
        }
        temp=temp->next;
        temp2=temp->next;
        
    }
}
void Matcher::FinalizeAndExport(){
    ofstream out;
    out.open("Matches.txt");
    while(ListProcess->head!=NULL){
        User*temp=ListProcess->head->next;
        out<<ListProcess->head->NETID<<'\t';
        for(int i=0;i<ListProcess->head->Matches.size();i++){
            out<<ListProcess->head->Matches[i]<<'\t';
        }
        out<<endl;
        delete ListProcess->head;
        ListProcess->head=temp;
    }
}

#endif /* Matcher_h */
