#pragma once

#include<vector>
#include "ExcelDriver\VectorsAndMatrices\NumericMatrix.hpp"
#include "Group.h"

class Experiment {
private:
	std::vector<Group> big_groups = std::vector<Group>(3); //0:beat 1:meet 2:miss
	double threshold = 5;                // 5~10%
	int resample_times = 1;            // 1~100
	NumericMatrix<double, long> AAR_avg= NumericMatrix<double, long>(3,91);
	NumericMatrix<double, long> CAAR_avg = NumericMatrix<double, long>(3, 91);
public:
	Experiment();
	Experiment(double t_h, int r_t);
	~Experiment();
	NumericMatrix<double, long> getAARavg();
	NumericMatrix<double, long> getCAARavg();
	double GetThreshold();
	bool SetThreshold(double t_h);
	int GetResampleTimes();
	bool SetResampleTimes(int r_t);
	Group Sampling(Group b_g);     //Random 40
	bool UpdateGroups(map<string, Stock>& allstocks_);
	bool DoExperiment();
};

