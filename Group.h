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
	vector<double> getAAR() { return AAR; }
	vector<double> getCAAR() { return CAAR; }
	bool pushStock(Stock s);
	bool compute();
};

