//Aleksandra Krzeminska, 15.11

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*already defined in WidmoCs.C

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
}*/

pair<bool, vector<double>> openAndReadBinFile(string file_name) {
    ifstream binaryFile(file_name, ios::binary);
    vector<double> data;

    if (!binaryFile) {
        cerr << "Nie można otworzyć pliku Cs-137.bin" << endl;
        return make_pair(false, data);;
    }

    double value;
    while (binaryFile.read(reinterpret_cast<char*>(&value), sizeof(double))) {
        data.push_back(value);
    }

    binaryFile.close();

    return make_pair(true, data);
}


Bool_t WidmoCsBin(string file_name = "Cs-137.bin") {
    pair<bool, vector<double>> result = openAndReadBinFile(file_name);
    if(!result.first) return kFALSE;
    for(auto val:result.second){
        cout<<val<<endl;
    }
    drawGraph(result.second);

    return kTRUE; 
}