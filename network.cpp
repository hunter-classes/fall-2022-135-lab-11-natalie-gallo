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
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
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

 // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
bool Network::follow(string usrn1, string usrn2){
    if (findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    } else {
        return false;
    }
}

 // Print Dot file (graphical representation of the network)
 
void Network::printDot(){
    cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++){
        string user = "@" + profiles[i].getUsername();
        cout << "\t\"" << user << "\"" << endl;
    }
    cout << "\n";
    for (int row = 0; row < numUsers; row++){
        for (int col = 0; col < numUsers; col++){
            if (following[row][col] == true){
                cout << "\t\"@" << profiles[row].getUsername() << "\" -> \"@" << profiles[col].getUsername() << "\"\n";
            }
        }
    }
    cout << "}\n";
}