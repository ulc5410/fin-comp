#pragma once

#include<map>
#include<string>
#include<vector>
using namespace std;
class Group
{
private:
	map<string, Stock> stocks;
	vector<double> AAR= vector<double>(91);
	vector<double> CAAR = vector<double>(91);
public:
	Group();
	~Group();
	vector<double> GetAAR() { return AAR; }
	vector<double> GetCAAR() { return CAAR; }
	bool PushStock(Stock s);
	bool Compute();
};

