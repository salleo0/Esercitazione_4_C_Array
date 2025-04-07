#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "iomanip"

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
	char tmp;
	for (unsigned int i = 0; i < numAssets; i++) {
		ifs >> assetFraction[i] >> tmp >> returnRate[i];	
	}
	
	return true;
}


double FinalValueOfPortfolio(const size_t& numAssets,
							 const double& startingCapital,
							 const double* const& returnRate,
							 const double* const& assetFraction)
{
	double finalCapital = 0;
	for (unsigned int i = 0; i < numAssets; i++) {
		const double &r = returnRate[i];
		const double &w = assetFraction[i];
		finalCapital += (1+r)*w*startingCapital;
	}
	return finalCapital;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
	
bool ExportResults(const string& outputFilePath,
				   const size_t& numAssets,
				   const double& startingCapital,
				   const double* const& returnRate,
				   const double* const& assetFraction,
				   const double& finalCapital)
{
	ofstream ofs;
	ofs.open(outputFilePath);
	
	if (ofs.fail())
	{
		cerr << "file open failed" << endl;
		return false;
	}
	
	
	ofs << fixed << setprecision(2) << "S = " << startingCapital;
	ofs << defaultfloat << ", n = " << numAssets << endl;
	ofs << "w = " << ArrayToString(numAssets, assetFraction) << endl;
	ofs << "r = " << ArrayToString(numAssets, returnRate) << endl;
	ofs << "Rate of return of portfolio: " << 1.0*(finalCapital - startingCapital)/startingCapital << endl;
	ofs << "V: " << fixed << setprecision(2) << finalCapital << endl;
	
	ofs.close();
	return true;
}