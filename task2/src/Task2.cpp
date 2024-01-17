/*---------------------------------------------------------------------------------------------
--	SOURCE FILE:	random.c - the code for the Caesar cipher for a simple substitution
--
--	DATE:			Jan 14, 2024
--				    Added personal function for assignment
--
--	REVISIONS:		(Date and nic_description)
--
--	DESIGNERS:		Based on the code by Aman Abdulla
--					Modified & redesigned: HyungJoon LEE: Jan 14, 2024
--
--	STUDENT:		HyungJoon LEE
-------------------------------------------------------------------------------------------------*/

#include "Task2.h"

const int MAXSUB = 28;
char sub[MAXSUB] = "qazwsxedcrfvtgbyhnujm ikolp";
char alphabet[MAXSUB] = "abcdefghijklmnopqrstuvwxyz";

string Task2::getFileNameInput(const string& prompt) {
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


bool Task2::isValidExtension(const string& fileName) {
    size_t dotPosition = fileName.find_last_of('.');
    if (dotPosition != string::npos) {
        string extension = fileName.substr(dotPosition + 1);
        if (extension == "txt") return true;
    }
    return false;
}


void Task2::encode(const string &inFile, const string &outFile) {
    char ch;
    ifstream fp1(inFile);
    ofstream fp2(outFile);

    if (!fp1) {
        cerr << "Input file is wrong" << endl;
        exit(1);
    }

    if (!fp2) {
        cerr << "Output file is wrong" << endl;
        exit(1);
    }

    while (fp1.get(ch)) {
        ch = tolower(ch);
        if (isalpha(ch) || ch == ' ')
            ch = sub[LocateIndex(alphabet, ch)];
        if (ch != '\0')
            fp2.put(ch);
    }
}


void Task2::decode(const string &inFile, const string &outFile) {
    char ch;
    ifstream fp1(inFile);
    ofstream fp2(outFile);

    if (!fp1) {
        cerr << "Input file is wrong" << endl;
        exit(1);
    }

    if (!fp2) {
        cerr << "Output file is wrong" << endl;
        exit(1);
    }

    while (fp1.get(ch)) {
        ch = tolower(ch);
        if (isalpha(ch) || ch == ' ')
            ch = alphabet[LocateIndex(sub, ch)];
        fp2.put(ch);
    }
}


int Task2::LocateIndex(const char *str, char ch) {
    for (int i = 0; i < MAXSUB; i++) {
        if (ch == str[i]) {
            return i;
        }
    }
    return 0;
}


void Task2::calculateFrequency(ifstream &fp) {
    char ch;
    totalCharacters = 0;
    while (fp.get(ch)) {
        ch = tolower(ch);
        if (isalpha(ch) || ch == ' ') {
            frequencyMap[ch]++;
            totalCharacters++;
        }
    }
}


void Task2::calculateProbability() {
    for (auto& pair : frequencyMap) {
        probabilityMap[pair.first] = static_cast<double>(pair.second) / totalCharacters;
    }
}


void Task2::calculateDistributions(const string &fileName, bool flag) {
    ifstream fp(fileName);
    if (!fp) {
        cerr << "Cannot open file for distribution calculation: " << fileName << endl;
        exit(1);
    }

    // Clear previous data
    frequencyMap.clear();
    probabilityMap.clear();
    totalCharacters = 0;

    // Calculate frequency of each character
    calculateFrequency(fp);

    // Calculate probability of each character
    calculateProbability();
    if (flag == INPUT)
        appendToCSV("plain.csv", "Plain txt result");
    else
        appendToCSV("encode.csv", "Encoded txt result");
    // Close the file stream
    fp.close();
}


void Task2::printConditionalProbabilities(const string& fileName) {
    unordered_map<char, double> plainTextProbabilities; // Fill this with actual data

    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        char ch;
        double prob;
        if (ss >> ch && ss.ignore(256, ',') && ss >> prob) {
            plainTextProbabilities[ch] = prob;
        }
    }

    int shift = 2; // The Caesar cipher shift

    // Print the conditional probabilities for the six most frequent letters
    for (char plainChar : {'e', 't', 'a', 'i', 'o', 'n'}) {
        // Calculate the corresponding cipher character given the shift
        char cipherChar = ((plainChar + shift) % 26) + 'a';

        // Print the conditional probability
        double probability = plainTextProbabilities.find(plainChar) != plainTextProbabilities.end() ? plainTextProbabilities[plainChar] : 0;
        cout << "P(" << plainChar << "|" << cipherChar << ") = " << probability << endl;
    }
}


void Task2::printProbabilities() const {
    for (const auto &entry : probabilityMap) {
        cout << "P(" << entry.first << ") = " << entry.second << endl;
    }
}


void Task2::appendToCSV(const string &fileName, const string &instruction) {
    ofstream file(fileName);

    if (!file) {
        cerr << "Cannot open file for appending: " << fileName << endl;
        exit(1);
    }

    file << instruction << endl;
    for (const auto &entry : probabilityMap) {
        file << entry.first << "," << entry.second << endl;
    }
    file << endl;
    file.close();
}
