#ifndef POPULATIONSELECTOR_H_
#define POPULATIONSELECTOR_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationSelector{
public:
	void udpdatePopulation( vector< Solution > population) = 0;
	virtual vector<Solution> selector() = 0;

private:
	double ratio;
	vector< Solution > population;
};

#endif /* POPULATIONSELECTOR_H_ */
