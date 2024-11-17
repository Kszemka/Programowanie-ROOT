//Aleksandra Krzeminska, 15.11

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
//#include ”WidmoCs.C”

using namespace std;

//drawHistogram already defined in WidmoCs.C


pair<bool, vector<double>>* openAndReadBinFile(const string& file_name) {
    ifstream binaryFile(file_name, ios::binary);
    vector<double> data;
    auto result = new pair<bool, vector<double>>(false, vector<double>());

    if (!binaryFile) {
        cerr << "Nie można otworzyć pliku Cs-137.bin" << endl;
        return result;
    }

    double value;
    while (binaryFile.read(reinterpret_cast<char*>(&value), sizeof(double))) {
        result->second.push_back(value);
    }

    binaryFile.close();

    result->first = true;
    return result;
}


Bool_t WidmoCsBin(const string& file_name = "Cs-137.bin") {
    pair<bool, vector<double>>* result = openAndReadBinFile(file_name);
    if (!result->first) {
        delete result;
        return false;
    }

    for(auto val:result->second){
        cout<<val<<endl;
    }
    drawHistogram(result->second);
    delete result;
    return kTRUE; 
}