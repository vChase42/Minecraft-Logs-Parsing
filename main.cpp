#include <iostream>
#include "utils.h"
#include <string>
#include "log.h"

using namespace std;


int main(){

    Log p;

    vector<string> messages = p.readFile("logs/2022-06-27-1.log");
    p.rows = p.parseMessages(messages);

    // p.printLogOfType("CHAT");
    // cout << p.getDuration().to_string() << endl;


    int t = '�';

    char c = t;

    cout << t << endl;
    cout << c << endl;

    cout << p.rows.back().message[1] << endl;

    t = p.rows.back().message[1];
    c = t;
    cout << t << endl;
    cout << c << endl;
}



// º or � == -89