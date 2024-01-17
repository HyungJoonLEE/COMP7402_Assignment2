#ifndef COMP7402_ASSIGNMENT2_TASK2_H
#define COMP7402_ASSIGNMENT2_TASK2_H


#include <iostream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <unordered_map>
#include <vector>

#define INPUT 0
#define OUTPUT 1


using namespace std;

class Task2 {
private:
    unordered_map<char, int> frequencyMap;  // To store frequency of each letter
    unordered_map<char, double> probabilityMap;  // To store probability of each letter
    int totalCharacters;  // Total number of characters counted

    void calculateFrequency(ifstream& fp);
    void calculateProbability();
public:
    string getFileNameInput(const string& prompt);
    bool isValidExtension(const string& fileName);
    void encode(const string& inFile, const string& outFile);
    void decode(const string& inFile, const string& outFile);
    int LocateIndex(const char* str, char ch);
    void calculateDistributions(const string& fileName, bool flag);
    void printConditionalProbabilities(const string& fileName);
    void printProbabilities() const;
    void appendToCSV(const string &fileName, const string &instruction);
};

#endif //COMP7402_ASSIGNMENT2_TASK2_H
