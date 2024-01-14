#ifndef COMP7402_ASSIGNMENT2_TASK1_H
#define COMP7402_ASSIGNMENT2_TASK1_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cctype>


using namespace std;

class Task1 {
private:
    unordered_map<char, int> _LMap;
public:
    string getFileNameInput(const string& prompt);
    bool isValidExtension(const string& fileName);
    int process(const string& fileName);
    int saveToCSV(const std::string& fileName);

};


#endif //COMP7402_ASSIGNMENT2_TASK1_H
