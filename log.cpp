#include "log.h"


Log::Log(): rows(){}

vector<string> Log::readFile(string fileName){
    ifstream file;
    vector<string> lines;
    string input;

    file.open(fileName);

    if(!file.is_open()){
        cout << "File " << fileName << " not found." << endl;
        exit(EXIT_FAILURE);
        cout << "this code should not run" << endl;
    }

    while(getline(file, input)){
        lines.push_back(input);
    }

    file.close();
    return lines;    
}

vector<Log::Row> Log::parseMessages(vector<string>& lines){
    vector<Row> rows;

    for(unsigned int i = 0; i < lines.size(); i++){    //ALL THE HARD PARSING WORK FOR EVERY SINGLE LOG SHOULD BE DONE HERE, NOWHERE ELSE
        //uhhhh soooo you just gotta find:
        //Time
        //Message Type. Especially if chat message
        //and the rest of the message itself
        Row row;
        if(hasTimeStamp(lines[i])){
            Time timeStamp = Time(parseBrackets(lines[i]));
            row.time = timeStamp;
            vector<string> types;
            if(parseAllBracketsUntil(lines[i],"CHAT",types,true,3)){
                row.type = types;
                row.message = lines[i];
            }else{
                row.type = types;
                row.message = lines[i];
            }

            rows.push_back(row);
        }else{
            rows.back().message = rows.back().message + "\n" + lines[i];
        }
    }
    return rows;
}


void Log::printLog(){
    for(auto x: rows){
        cout << x.time.asTimeStamp();
        cout << x.message << endl;
    }
}

void Log::printTypes(){
    for(auto x: rows){
        cout << x.time.asTimeStamp();
        for(auto y: x.type){
            cout << y << ", ";
        }
        cout << endl;
    }
}

void Log::printLogOfType(string type){
    for(auto x: rows){
        for(auto y: x.type){
            if(y == type){
                cout << x.time.asTimeStamp();
                cout << x.message << endl;
                break;
            }
        }
    }
}

Time Log::getDuration(){
    return rows.back().time - rows.front().time;
}