#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Function to read sequences and their structures from the file
void readData(const string &filename, vector<string> &names, vector<string> &sequences, vector<string> &structures) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        names.push_back(line); // Protein name
        getline(file, line);    // Length (not used)
        getline(file, line);    // Amino acid sequence
        sequences.push_back(line);
        getline(file, line);    // Secondary structure
        structures.push_back(line);
    }
    
    file.close();
}

// Function to calculate frequencies of amino acids in secondary structures
map<string, map<string, int>> calculateFrequencies(const vector<string> &sequences, const vector<string> &structures) {
    map<string, map<string, int>> frequencies;

    for (size_t i = 0; i < sequences.size(); ++i) {
        const string &sequence = sequences[i];
        const string &structure = structures[i];

        for (size_t j = 0; j < sequence.length(); ++j) {
            string aminoAcid(1, sequence[j]); // Get amino acid as a string
            string secStructure(1, structure[j]); // Get corresponding secondary structure

            frequencies[aminoAcid][secStructure]++;
        }
    }
    
    return frequencies;
}

// Function to predict secondary structure based on frequencies
string predictStructure(const string &sequence, const map<string, map<string, int>> &frequencies) {
    string prediction;

    for (char aa : sequence) {
        string aminoAcid(1, aa);
        if (frequencies.find(aminoAcid) != frequencies.end()) {
            // Find the secondary structure with the highest count
            string maxStructure;
            int maxCount = 0;
            for (const auto &entry : frequencies.at(aminoAcid)) {
                if (entry.second > maxCount) {
                    maxCount = entry.second;
                    maxStructure = entry.first;
                }
            }
            prediction += maxStructure;
        } else {
            // If the amino acid is not found, classify as coil
            prediction += 'C';
        }
    }

    return prediction;
}

int main() {
    vector<string> trainNames, trainSequences, trainStructures;
    vector<string> testNames, testSequences;

    // Read training data
    readData("trainSS.txt", trainNames, trainSequences, trainStructures);

    // Read test data
    readData("testSS.txt", testNames, testSequences, trainStructures); // No structures needed for test

    // Calculate frequencies from training data
    map<string, map<string, int>> frequencies = calculateFrequencies(trainSequences, trainStructures);

    // Predict structures for the test sequences
    for (size_t i = 0; i < testSequences.size(); ++i) {
        string prediction = predictStructure(testSequences[i], frequencies);

        // Output results
        cout << testNames[i] << endl;
        cout << testSequences[i].length() << endl; // Length of the amino acid sequence
        cout << testSequences[i] << endl;          // Amino acid sequence
        cout << prediction << endl;                 // Predicted secondary structure
    }

    return 0;
}
