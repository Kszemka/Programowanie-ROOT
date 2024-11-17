//Aleksandra Krzeminska, 15.11

Bool_t LoadAllMacros() {
    if (gROOT->ProcessLine(".L WidmoCs.C") != 0) {
        std::cerr << "Error loading WidmoCs.C" << std::endl;
        return kFALSE;
    }
    if (gROOT->ProcessLine(".L WidmoCsBin.C") != 0) {
        std::cerr << "Error loading WidmoCsBin.C" << std::endl;
        return kFALSE;
    }
    if (gROOT->ProcessLine(".L HistogramStack.C") != 0) {
        std::cerr << "Error loading HistogramStack.C" << std::endl;
        return kFALSE;
    }
    if (gROOT->ProcessLine(".L RewriteFile.C") != 0) {
        std::cerr << "Error loading RewriteFile.C" << std::endl;
        return kFALSE;
    }

    return kTRUE;
}
