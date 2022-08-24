#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>


#include "utils.h"

using namespace std;

class Log{
    struct Row{
        string message;
        vector<string> type;
        Time time;
    };

public:

    Log();

    void printLog();
    void printTypes();
    void printLogOfType(string type);

    Time getDuration();

    //a function that can use color! im pretty sure windows powershell can support that!

// private:
    static vector<string> readFile(string fileName);
    static vector<Row> parseMessages(vector<string>& messages);

    vector<Row> rows;

};




#endif