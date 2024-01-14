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
char alphabet[MAXSUB] = "abcdefghijklmnopqrstuvwxyz ";

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
    if (dotPosition != std::string::npos) {
        std::string extension = fileName.substr(dotPosition + 1);
        if (extension == "txt") return true;
    }
    return false;
}


void Task2::encode(const string &inFile, const string &outFile) {
    char ch;
    std::ifstream fp1(inFile);
    std::ofstream fp2(outFile);

    if (!fp1) {
        std::cerr << "Input file is wrong" << std::endl;
        exit(1);
    }

    if (!fp2) {
        std::cerr << "Output file is wrong" << std::endl;
        exit(1);
    }

    while (fp1.get(ch)) {
        ch = tolower(ch);
        if (std::isalpha(ch) || ch == ' ')
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
        cerr << "Input file is wrong" << std::endl;
        exit(1);
    }

    if (!fp2) {
        cerr << "Output file is wrong" << std::endl;
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
