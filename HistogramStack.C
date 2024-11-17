//Aleksandra Krzeminska, 15.11

#include <TH1F.h>
#include <THStack.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TLegend.h>

Bool_t DrawHistograms() {
    TRandom3 rand;

    auto hs = new THStack("hs","");
    TH1F *h1 = new TH1F("h1", "Gaussian Distribution;Value;Frequency", 100, -2, 10);
    h1->SetFillColor(kRed);
    TH1F *h2 = new TH1F("h2", "Exponential Distribution;Value;Frequency", 100, -2, 10);
    h2->SetFillColor(kGreen);
    TH1F *h3 = new TH1F("h3", "Poisson Distribution;Value;Frequency", 100, -2, 10);
    h3->SetFillColor(kBlue);
    TH1F *h4 = new TH1F("h4", "Uniform Distribution;Value;Frequency", 100, -2, 10);
    h4->SetFillColor(kYellow);

    for (int i = 0; i < 10000; i++) {
        h1->Fill(rand.Gaus(2, 1));
        h2->Fill(rand.Exp(1));
        h3->Fill(rand.Poisson(2));
        h4->Fill(rand.Uniform(1));
    }

    TCanvas *c = new TCanvas("c", "Histograms", 800, 600);
    c->Divide(2, 0);

    hs->Add(h1);
    hs->Add(h2);
    hs->Add(h3);
    hs->Add(h4);
    
    TLegend *leg1 = new TLegend(0.55, 0.7, 0.95, 0.9);
    leg1->AddEntry(h1, "Gaussian Distribution", "f");
    leg1->AddEntry(h2, "Exponential Distribution", "f");
    leg1->AddEntry(h3, "Poisson Distribution", "f");
    leg1->AddEntry(h4, "Uniform Distribution", "f");
    leg1->SetTextSize(0.03);

    c->cd(1);
    hs->Draw();
    leg1->Draw();

    TLegend *leg2 = new TLegend(0.45, 0.7, 0.95, 0.9);
    leg2->AddEntry(h1, "Gaussian Distribution in 3d", "f");
    leg2->AddEntry(h2, "Exponential Distribution in 3d", "f");
    leg2->AddEntry(h3, "Poisson Distribution in 3d", "f");
    leg2->AddEntry(h4, "Uniform Distribution in 3d", "f");
    leg2->SetTextSize(0.03);

    c->cd(2);
    hs->Draw("lego1");
    leg2->Draw();

    c->Update();

    return kTRUE;
}
