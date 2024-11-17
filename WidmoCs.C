//Aleksandra Krzeminska, 15.11

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFile.h>
#include <TLine.h>
#include <TText.h>
using namespace std;

void drawHistogram(vector<double>& data){
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
    
    TLine photoPeak(260, 0, 260, 1500);
    photoPeak.SetLineColor(kRed);
    photoPeak.Draw();

    TText photoPeak_txt(260, 1300, "662 keV fotopik");
    photoPeak_txt.SetTextFont(42);
    photoPeak_txt.SetTextSize(0.025);
    photoPeak_txt.SetTextColor(kRed);
    photoPeak_txt.Draw();

    TLine compton(190, 0, 190, 1500);
    compton.SetLineColor(kGreen);
    compton.Draw();

    TText compton_txt(190, 900, "Comptons' edge");
    compton_txt.SetTextFont(42);
    compton_txt.SetTextSize(0.025);
    compton_txt.SetTextColor(kGreen);
    compton_txt.Draw();

    TLine backscatterPeak(80, 0, 80, 1500);
    backscatterPeak.SetLineColor(kBlack);
    backscatterPeak.Draw();

    TText backscatter_txt(80, 1300, "backscatter peak");
    backscatter_txt.SetTextFont(42);
    backscatter_txt.SetTextSize(0.025);
    backscatter_txt.SetTextColor(kBlack);
    backscatter_txt.Draw();

    canvas.Update();
    canvas.SaveAs("cs137_spectrum.png");
    canvas.Write("canvas");
    h.Write("histogram");

    outfile.Close();    
}

pair<bool, vector<double>>* openAndReadFile(const string& file_name) {
    fstream file;
    file.open(file_name, ios::in);
    auto result = new pair<bool, vector<double>>(false, vector<double>());

    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return result;
    }

    cout << "File opened." << endl;
    double value;
    while (file >> value) {
        result->second.push_back(value);
    }
    file.close();
    result->first = true;

    return result;
}

bool WidmoCs(const string& file_name = "Cs-137.dat") {
    pair<bool, vector<double>>* result = openAndReadFile(file_name);
    if (!result->first) {
        delete result;
        return false;
    }

    drawHistogram(result->second);

    delete result;
    return true;
}
