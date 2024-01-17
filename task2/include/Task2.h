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
    unordered_map<char, double> plainTxtProb;
    unordered_map<char, double> cipherTxtProb;
    int totalCharacters;  // Total number of characters counted

    void calculateFrequency(ifstream& fp);
    void calculateProbability();
public:
    string getFileNameInput(const string& prompt);
    bool isValidExtension(const string& fileName);
    void encode(const string& inFile, const string& outFile, int shift);
    int LocateIndex(const char* str, char ch);
    void calculateDistributions(const string& fileName, bool flag);
    void printProbabilities() const;
    void setConditionalProbabilities(const string& fileName1, const string& fileName2);
    void printConditionalProbabilities(int key);
    void appendToCSV(const string &fileName, const string &instruction);
};

#endif //COMP7402_ASSIGNMENT2_TASK2_H
