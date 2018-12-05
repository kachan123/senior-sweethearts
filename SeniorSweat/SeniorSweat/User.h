//
//  User.h
//  SeniorSweat
//
//  Created by Roberto D'angelo-Cosme on 11/23/18.
//  Copyright © 2018 Roberto D'angelo-Cosme. All rights reserved.
//

#ifndef User_h
#define User_h
#include <string>
#include <vector>
using namespace std;
class User{
    friend class Matcher;
    friend class UserList;
    
public:
    User();
    User(string);

    string NETID;
    vector<string> Choices;
    vector<string> Matches;
    
    User*next;
    
};
User::User(){
    next=NULL;
    NETID="XXXX";
}
User::User(string ID){
    NETID=ID;
    next=NULL;
}
#endif /* User_h */
