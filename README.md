# Protein-Secondary-Structure-Predictor-project
This project implements a predictor for protein secondary structures based on amino acid sequences using a frequency-based approach. The predictor is designed to classify each amino acid in a protein sequence as either a coil (C), helix (H), or strand (E) based on observed frequencies from training data.

# Features
**Frequency Calculation:** Computes frequencies of amino acids in various secondary structures from training data.
**Prediction:** Predicts secondary structures for a given set of protein sequences based on calculated frequencies.
**Input/Output:** Reads input from text files and outputs predictions directly to the console.

# Files
**ProteinStructurePredictor.cpp:** The main C++ source file containing the predictor logic.
**trainSS.txt:** Training dataset containing protein sequences and their associated secondary structures.
**testSS.txt:** Test dataset containing protein sequences for which secondary structures will be predicted.

# Setup Instructions
**Prerequisites**
Ensure you have a C++ compiler installed on your machine.

**g++ ProteinStructurePredictor.cpp -o ProteinStructurePredictor**
**./ProteinStructurePredictor**
