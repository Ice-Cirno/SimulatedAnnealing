#include "SA.h"

SA::SA() :Temperature(TEMPERATURE_INIT) {}

void SA::Do(){
	double gain;

	ReadFile();
	Init();
	while (Temperature > TEMPERATURE_GOAL) {
		int i = RES;
		while (--i) {
			GenerateNew();
			gain = static_cast<int>(_max_or_min) * (Estimate(new_root) - Estimate(curr_root));
			if (gain < 0 || AcceptBadRoot()) {
				//accept newroot...
			}
			if (gain < 0) {
				//fresh bestroot...
			}
		}
		Temperature *= ANEALING_COEFF;
	}




}
