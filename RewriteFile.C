//Aleksandra Krzeminska, 15.11

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*already defined in WidmoCs.C
pair<bool, vector<double>> openAndReadFile(string file_name) {
    ifstream file(file_name);
    vector<double> data;

    if (!file.is_open()) {
        cout << "Error opening file: " << file_name << endl;
        return make_pair(false, data);
    }

    cout << "File opened." << endl;
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();
    return make_pair(true, data);
}*/

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
    pair<bool, vector<double>> result = openAndReadFile(file_name);
    if (!result.first) return kFALSE;

    saveDataToBinary(result.second);

    ifstream binaryFile("Cs-137.bin", ios::binary);
    if (!binaryFile) {
        cerr << "Nie można otworzyć pliku Cs-137.bin" << endl;
        return kFALSE;
    }

    cout << "Zawartość pliku Cs-137.bin:" << endl;
    double value;
    while (binaryFile.read(reinterpret_cast<char*>(&value), sizeof(double))) {
        cout << value << endl;
    }
    binaryFile.close();
    return kTRUE;
}
