#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <string>

#include "../model/Solution.h"

#include "PopulationGenerator.h"
#include "StoppingCriterion.h"

using namespace std;

class Algorithm {
private:

	vector< Solution > population;
//	vector< Solution > elitePopulation;
//	vector< Solution > selection;
//	vector< Solution > offspring;

	PopulationGenerator * generator;
	StoppingCriterion * criterio;

public:
	Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio
	);

	~Algorithm();

	Solution lets_go();
};

#endif /* ALGORITHM_H_ */
