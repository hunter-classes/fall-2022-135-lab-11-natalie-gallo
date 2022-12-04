#include <iostream>
#include <string>
#include "profile.h"
using namespace std;

// Profile constructor for a user (initializing 
// private variables username=usrn, displayname=dspn)
Profile::Profile(std::string usrn, std::string dspn){
    username = usrn;
    displayname = dspn;
}

// Default Profile constructor (username="", displayname="")
Profile::Profile(){
    username = "";
    displayname = "";
}

// Return username
string Profile::getUsername(){
    return username;
}

// Return name in the format: "displayname (@username)"
string Profile::getFullName(){
    string name = displayname + " (@" + username + ")";
    return name;
}

// Change display name
void Profile::setDisplayName(string dspn){
    displayname = dspn;
}