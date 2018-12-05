//
//  UserList.h
//  SeniorSweat
//
//  Created by Roberto D'angelo-Cosme on 11/23/18.
//  Copyright © 2018 Roberto D'angelo-Cosme. All rights reserved.
//

#ifndef UserList_h
#define UserList_h
using namespace std;

class UserList{
    friend class Matcher;
public:
    UserList();
    void add(string);
    void removeFront();
    void print();

    User* head;
    User* last;
};

UserList::UserList(){
    head=NULL;
    last=NULL;
}

void UserList::print(){
    User*temp=head;
    while(temp!=NULL){
        cout<<temp->NETID<<" Chose: ";
        for(int i=0; i<temp->Choices.size();i++){
            cout<<temp->Choices[i]<<" ";
        }
        
        cout<<endl;
        temp=temp->next;
    }
}
void UserList::add(string u){
    User*temp=new User(u);
    if(head==NULL){
        last=temp;
    }
    temp->next=head;
    head=temp;
}
void UserList::removeFront(){
    User*temp=head->next;
    delete head;
    head=temp;
}


#endif /* UserList_h */


