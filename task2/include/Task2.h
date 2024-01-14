#ifndef COMP7402_ASSIGNMENT2_TASK2_H
#define COMP7402_ASSIGNMENT2_TASK2_H


#include <iostream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>


using namespace std;

class Task2 {
private:
public:
    string getFileNameInput(const string& prompt);
    bool isValidExtension(const string& fileName);
    void encode(const std::string& inFile, const std::string& outFile);
    void decode(const std::string& inFile, const std::string& outFile);
    int LocateIndex(const char* str, char ch);
};

#endif //COMP7402_ASSIGNMENT2_TASK2_H
