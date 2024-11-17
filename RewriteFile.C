//Aleksandra Krzeminska, 15.11

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
//#include ”WidmoCs.C”

using namespace std;

// openAndReadFile already defined in WidmoCs.C

void saveDataToBinary(const vector<double>& data) {
    ofstream outputFile("Cs-137.bin", ios::binary);
    if (!outputFile) {
        cout << "Nie można otworzyć pliku Cs-137.bin" << endl;
        return;
    }

    for (const auto& num : data) {
        outputFile.write(reinterpret_cast<const char*>(&num), sizeof(double));
    }
    outputFile.close();
}

Bool_t Rewrite(string file_name = "Cs-137.dat") {
    pair<bool, vector<double>>* result = openAndReadFile(file_name);
    if (!result->first) {
        delete result;
        return false;
    }

    saveDataToBinary(result->second);

    ifstream binaryFile("Cs-137.bin", ios::binary);
    if (!binaryFile) {
        cerr << "Nie można otworzyć pliku Cs-137.bin" << endl;
        return kFALSE;
    }

//    cout << "Zawartość pliku Cs-137.bin:" << endl;
//    double value;
//    while (binaryFile.read(reinterpret_cast<char*>(&value), sizeof(double))) {
//        cout << value << endl;
//    }

    delete result;
    binaryFile.close();
    return kTRUE;
}
