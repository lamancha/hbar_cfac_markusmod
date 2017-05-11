#include <iostream>
#include <map>
#include <TSystem.h>
#include "QuantumNumbers.hh"
#include "rfacEssentialData.hh"
#include "EnergyLevel.hh"
#include <TTree.h>
#include <TFile.h>

using namespace std;


TTree * T;
rfacEssentialData * myEssentialData;

map<QuantumNumbers, EnergyLevel> subEssential;


map<QuantumNumbers, Double_t> calculated;

int main();

double TimeToGS(const QuantumNumbers current, Double_t fieldValue);

double TimeToGSdoIt(const QuantumNumbers current, Double_t fieldValue);
