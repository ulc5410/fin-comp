#include "Experiment.h"



Experiment::Experiment() {
}

Experiment::Experiment(double t_h, int r_t) {
	threshold = t_h;
	resample_times = r_t;
}


Experiment::~Experiment() {
}

NumericMatrix<double, long> Experiment::getAARavg() {
	return AAR_avg;
}

NumericMatrix<double, long> Experiment::getCAARavg() {
	return CAAR_avg;
}

double Experiment::GetThreshold() {
	return threshold;
}

bool Experiment::SetThreshold(double t_h) {
	threshold = t_h;
	return true;
}

int Experiment::GetResampleTimes() {
	return resample_times;
}

bool Experiment::SetResampleTimes(int r_t) {
	resample_times = r_t;
	return true;
}

Group Experiment::Sampling(Group b_g) {
	return Group();
}

bool Experiment::UpdateGroups(map<string, Stock>& allstocks_) {
	if (allstocks_.empty()) {
		return false;
	}
	for (auto i = allstocks_.begin(); i != allstocks_.end(); i++)
	{
		if (i->second.GetSurprise() > threshold) {
			big_groups[0].pushStock(i->second);
		}
		else if (i->second.GetSurprise() < -threshold) {
			big_groups[2].pushStock(i->second);
		}
		else {
			big_groups[1].pushStock(i->second);
		}
	}
	return true;
}

bool Experiment::DoExperiment() {
	Group SubGroup = Sampling(big_groups[0]);
	SubGroup.Compute();
	for (int i = 0; i < 91; i++) {
		AAR_avg[0][i] = SubGroup.GetAAR()[i];
		CAAR_avg[0][i] = SubGroup.GetCAAR()[i];
	}

	for (int i = 1; i < resample_times; ++i) {
		SubGroup = Sampling(big_groups[i]);
		SubGroup.Compute();
		for (int j = 0; i < 91; j++) {
			AAR_avg[i][j] = SubGroup.GetAAR()[j];
			CAAR_avg[i][j] = SubGroup.GetCAAR()[j];
		}
	}
}