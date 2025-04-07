#pragma once

#include <iostream>
#include <sstream>
using namespace std;

// ImportData legge i dati dal file inputFilePath
// numAssets: numero degli asset in cui si investe
// startingCapital: capitale da investire
// returnRate: tasso di guadagno su ogni asset
// assetFraction: frazione del capitale che si investe su un capitale
// restituisce i dati letti nel file, true se tutto va a buon fine, false
// ci sono errori nella lettura
bool ImportData(const string& inputFilePath,
				size_t& numAssets,
				double& startingCapital,
				double*& returnRate,
				double*& assetFraction);
				