#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"

using namespace std;

bool ImportData(const string& inputFilePath,
				size_t& numAssets,
				double& startingCapital,
				double*& returnRate,
				double*& assetFraction)
{
	ifstream ifs(inputFilePath);
	if (ifs.fail())
		return false;
	
	/* LEGGE PRIMA RIGA E ESTRAE IL CAPITALE INIZIALE */
	string line;
	getline(ifs, line);
	startingCapital = stod(line.erase(0,2));
	
	
	/* LEGGE SECONDA RIGA E ESTRAE NUMERO DI ASSET */
	getline(ifs, line);
	numAssets = stoi(line.erase(0,2));
	
	/* LEGGE TERZA RIGA E DISCARD (non serve: contiene solo nomi variabili) */
	getline(ifs, line);
	
	/* INIZIALIZZAZIONE returnRate E assetFraction E ESTRAZIONE DEI DATI */
	returnRate = new double[numAssets];
	assetFraction = new double[numAssets];
	stringstream ss;
	char tmp;
	for (unsigned int i = 0; i < numAssets; i++) {
		getline(ifs, line);
		ss << line;
		ss >> assetFraction[i] >> tmp >> returnRate[i];		
	}
	
	return true;
}


	
		
	