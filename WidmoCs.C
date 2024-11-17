#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TFile.h"
#include "TLine.h"
#include "TText.h" 
using namespace std;

void drawGraph(vector<double> data){
    TFile outfile("WidmoCs137.root", "RECREATE");
    TH1F h("histogram", "Widmo cezu 137;kanal;zliczenia", data.size(), 0, data.size());

    for (int i = 0; i < data.size(); ++i) {
        h.SetBinContent(i + 1, data[i]);
        h.SetBinError(i + 1, sqrt(data[i]));
    }

    TCanvas canvas("canvas", "Widmo cezu 137", 800, 600);
    h.Draw("E");
    h.SetLineColor(kBlue);
    h.GetXaxis()->SetRangeUser(0, 400);
    
    TLine photopeak(260, 0, 260, 1500);
    photopeak.SetLineColor(kRed);
    photopeak.Draw();

    TText photopeak_txt(260, 1300, "?");
    photopeak_txt.SetTextFont(42);
    photopeak_txt.SetTextSize(0.025);
    photopeak_txt.SetTextColor(kRed);
    photopeak_txt.Draw();

    canvas.Update();
    canvas.SaveAs("cs137_spectrum.png");
    canvas.Write("canvas");
    h.Write("histogram");

    outfile.Close();    
}

pair<bool,vector<double>> openAndReadFile(string file_name){
    fstream file;
    vector<double> data;
    file.open(file_name, ios::in);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return make_pair(false, data);
    }

    cout << "File opened." << endl;
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    return make_pair(true, data);

    file.close();
}

Bool_t WidmoCs(string file_name = "Cs-137.dat") {
    pair<bool, vector<double>> result = openAndReadFile(file_name);
    if(!result.first) return kFALSE;
    drawGraph(result.second);

    return kTRUE; 
}
