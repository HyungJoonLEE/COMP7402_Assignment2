#include "Task2.h"

int main() {
    Task2 t2;
    string inFile = t2.getFileNameInput
            ("Please enter the name of the text file to read from (e.g., 'input.txt'): ");
    string outFile = t2.getFileNameInput
            ("Please enter the name of the text file to write to (e.g., 'output.txt'): ");

    t2.encode(inFile, outFile);
    t2.decode(outFile, "r2.txt");
}

