#include "Task1.h"

string Task1::getFileNameInput(const string& prompt) {
    string input;
    do {
        cout << prompt;
        cin >> input;
        if (!isValidExtension(input)) {
            cout << "Invalid extension. Please try again." << endl;
        }
    } while (!isValidExtension(input));
    return input;
}


bool Task1::isValidExtension(const string& fileName) {
    size_t dotPosition = fileName.find_last_of('.');
    if (dotPosition != std::string::npos) {
        std::string extension = fileName.substr(dotPosition + 1);
        if (extension == "txt" || extension == "csv") return true;
    }
    return false;
}


int Task1::process(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return -1;
    }

    char ch;

    // Count letter frequencies
    while (inputFile >> ch) {
        ch = tolower(ch);
        if (isalpha(ch)) {
            _LMap[ch]++;
        }
    }

    inputFile.close();
    return 1;
}

int Task1::saveToCSV(const string &fileName) {
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 0;
    }

    outputFile << "letter,count\n"; // CSV Header
    for (const auto& pair : _LMap) {
        outputFile << pair.first << "," << pair.second << "\n";
    }

    outputFile.close();
    return 1;
}





