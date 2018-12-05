//
//  main.cpp
//  SeniorSweat
//
//  Created by Roberto D'angelo-Cosme on 11/23/18.
//  Copyright © 2018 Roberto D'angelo-Cosme. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Matcher.h"
#include "UserList.h"
#include <sstream>
using namespace std;
int main(int argc, const char * argv[]) {
    string s="";
    fstream InputFile;
    InputFile.open(argv[1]);
    
    //eliminates question from stream.
    getline(InputFile,s);
    UserList UL;
    UserList* l = &UL;
    
    
    while(getline(InputFile,s)){
        stringstream userData;
        userData<<s;
        string q="";
        userData>>q;//date
        userData>>q;//time
        userData>>q;//ID
        
        l->add(q); 
        while(userData>>q){
            l->head->Choices.push_back(q);
        }
       
    }
    
    
    //UL.print();
    Matcher m(l);
    m.Match();
    m.FinalizeAndExport();
    
    
    
    return 0;
}
