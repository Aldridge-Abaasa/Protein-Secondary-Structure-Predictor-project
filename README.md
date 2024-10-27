# Protein-Secondary-Structure-Predictor-project
This project implements a predictor for protein secondary structures based on amino acid sequences using a frequency-based approach. The predictor is designed to classify each amino acid in a protein sequence as either a coil (C), helix (H), or strand (E) based on observed frequencies from training data.

# Features
**Key Features of the C++ Script**
- Data Reading: The script reads protein names, sequences, and their corresponding secondary structures from the training data and reads only names and sequences from the test data.
- Frequency Calculation: It calculates the frequency of each amino acid being associated with different secondary structures.
- Prediction Logic: The script predicts the secondary structure for each amino acid in the test sequences based on the most frequently observed structure in the training data. If an amino acid does not appear in the training data, it defaults to predicting a coil (C).
- Output: It outputs the protein name, length of the sequence, the sequence itself, and the predicted secondary structure.

# Files
**ProteinStructurePredictor.cpp:** The main C++ source file containing the predictor logic.
**trainSS.txt:** Training dataset containing protein sequences and their associated secondary structures.
**testSS.txt:** Test dataset containing protein sequences for which secondary structures will be predicted.

# Setup Instructions
**Prerequisites**
Ensure you have a C++ compiler installed on your machine.

**g++ ProteinStructurePredictor.cpp -o ProteinStructurePredictor**
**./ProteinStructurePredictor**
