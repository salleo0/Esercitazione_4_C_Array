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
				
// FinalValueOfPortfolio restituisce il valore finale del capitale dato dal 
// guadagno su tutti gli asset
double FinalValueOfPortfolio(const size_t& numAssets,
							 const double& startingCapital,
							 const double* const& returnRate,
							 const double* const& assetFraction);
							 
// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);

// esporta i dati in un file di testo "results.txt"				 
bool ExportResults(const string& outputFilePath,
				   const size_t& numAssets,
				   const double& startingCapital,
				   const double* const& returnRate,
				   const double* const& assetFraction,
				   const double& finalCapital);