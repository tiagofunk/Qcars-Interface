#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <string>
#include <vector>

#include "../model/Solution.h"

#include "PopulationGenerator.h"
#include "StoppingCriterion.h"
#include "PopulationOperator.h"
#include "PopulationSelector.h"

using namespace std;

class Algorithm {
private:

	vector< Solution > population;
	vector< Solution > elitePopulation;

	PopulationGenerator * generator;
	StoppingCriterion * criterio;
	PopulationSelector * elite;

	vector< PopulationOperator * > operatorsBeforeLoop;

public:
	Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio,
		PopulationSelector * elite
	);
	~Algorithm();

	Solution lets_go();

	void addBeforeLoop( vector< PopulationOperator * > operators );
};

#endif /* ALGORITHM_H_ */
