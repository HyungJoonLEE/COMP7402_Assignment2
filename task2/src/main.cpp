#include "Task2.h"

int main() {
    Task2 t2;
    int offset = 3;

    // Get file names
//    string inFile = t2.getFileNameInput("Please enter the name of the text file to read from (e.g., 'input.txt'): ");
//    string outFile = t2.getFileNameInput("Please enter the name of the text file to write to (e.g., 'output.txt'): ");
//
//    // Encode the input file to produce the ciphertext in the output file
//    t2.encode(inFile, outFile, offset);
//
//    // Calculate and print the probability distributions for the input file (plaintext)
//    cout << "Probability distributions for the input file (plaintext):" << endl;
//    t2.calculateDistributions(inFile, INPUT);
//    // You would need to implement a method to print the calculated probabilities
//    t2.printProbabilities(); // Implement this method in Task2 class
//
//    // Calculate and print the probability distributions for the output file (ciphertext)
//    cout << "Probability distributions for the output file (ciphertext):" << endl;
//    t2.calculateDistributions(outFile, OUTPUT);
//    // Again, you would need to implement a method to print the calculated probabilities
//    t2.printProbabilities(); // Implement this method in Task2 class
//
//    // Print conditional probabilities
    t2.setConditionalProbabilities("plain.csv", "encode.csv");
    t2.printConditionalProbabilities(3);
//    for (int i = 1; i < 27; i++) {
//    }
}

