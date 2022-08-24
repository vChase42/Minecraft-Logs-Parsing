#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

struct Time{

    double seconds;

    Time(){
        seconds = 0;
    }
    Time(double s){seconds = s;}
    Time(string format){
        if(format.size() != 8){
            cout << "Class Time: Incorrect time input. Figure out how to output stack? --> " + format << endl;
            seconds = 0;
            return;
        }
        int h = stoi(format.substr(0,2));
        int m = stoi(format.substr(3,2));
        int s = stoi(format.substr(6,2));
        seconds = s + m*60 + h*3600;
    }

    double getSeconds(){return seconds;}
    double getMinutes(){return seconds/60.0;}
    double getHours(){return seconds/360.0;}

    void addSeconds(double s){seconds += s;}
    void addMinutes(double m){seconds += m*60.0;}
    void addHours(double h){seconds += h*3600.0;}

    string to_string(){
        int h = seconds/3600.0;
        double remainder = seconds - h*3600.0;
        int m = remainder/60.0;
        int s = remainder - m*60.0;

        return (std::to_string(h) + " Hours, " + std::to_string(m) + " Minutes, " + std::to_string(s) + " Seconds");
    }

    string asTimeStamp(){
        int h = seconds/3600.0;
        double remainder = seconds - h*3600.0;
        int m = remainder/60.0;
        int s = remainder - m*60.0;
        return ('[' + std::to_string(h) + ':' + std::to_string(m) + ':' + std::to_string(s) + ']');   //learn how to format so each number is printed with 2 digits
    }

    Time operator-(Time rhs){
        return Time(abs(this->seconds - rhs.seconds));
    }

};


inline string parseBrackets(string& s, bool snip = true, unsigned int maxCharUntilFirstBracket = 999){
    int index1 = -1;
    int index2 = -1;
    for(unsigned int i = 0; i < s.size(); i++){
        if(i > maxCharUntilFirstBracket){
            break;
        }
        if(s[i] == '['){
            for(unsigned int j = i; j < s.size(); j++){
                if(s[j] == ']'){
                    index1 = i;
                    index2 = j;
                    break;
                }
            }
            break;
        }
    }
    if(index2 == -1){
        // cout << "EXCEPTION: parseBrackets failed" << endl;
        throw -1;
    }

    string result = s.substr(index1+1,index2-index1 -1);
    if (snip)
        s = s.substr(index2 + 1,s.size()-1);
    return result;
}

inline bool parseBracketsUntil(string& s, string until, vector<string>& output, bool snip = true){
    string out;
    bool flag = true;
    do{
        try{
        out = parseBrackets(s,snip);
        }catch(int e){
            flag = false;
            break;
            // maybe have an exception and throw all the outputs found so far
        }
        output.push_back(out);

    }while(out != until);

    return flag;
}

inline bool parseAllBracketsUntil(string& s, string until, vector<string>& output, bool snip, int maxCharBetweenBrackets){
    string out;
    bool flag = true;
    do{
        try{
        out = parseBrackets(s,snip,maxCharBetweenBrackets);
        }catch(int e){
            flag = false;
            break;
            // maybe have an exception and throw all the outputs found so far
        }
        output.push_back(out);

    }while(out != until);

    return flag;
}
//if i could get a REALLY customizable parsebrackets funtion/system going that would be VERY convenient



inline bool hasTimeStamp(string input){
    if(input.size() > 10 && input[0] == '[' && input[3] == ':' && input[6] == ':' && input[9] == ']')
        return true;
    return false;
}



#endif