#include <iostream>
#include <string>
#include <cctype>
#include "network.h"
#include "profile.h" //not sure abt this..
using namespace std;

int Network::findID (string usrn){
    int id;
    for (int i = 0; i < numUsers; i++){
        std::string user = profiles[i].getUsername();

        if (user == usrn){
           id = i;
           return id;
        }
    }

    return -1;
}

Network::Network(){
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn){

    bool validation = true;
    //the new username usrn must be a non-empty alphanumeric string,
    for (int i = 0; i < usrn.length(); i++){
        char ch = usrn[i];
        if (!isalnum(ch)){
            validation = false;
        }
    }
    //there is no other users in the network with the same username,
    if (findID(usrn) != -1){
        validation = false;
    }
    //the array profiles is not full.
    if (numUsers < MAX_USERS && validation == true){
        Profile newUser(usrn, dspn);
        profiles[numUsers] = newUser;
        numUsers = numUsers + 1;
    } else {
        validation = false;
    }

    return validation;
}
