#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <string>
#include <vector>

#include "../model/Solution.h"

#include "PopulationGenerator.h"
#include "StoppingCriterion.h"
#include "PopulationOperator.h"

using namespace std;

class Algorithm {
private:

	vector< Solution > population;
//	vector< Solution > elitePopulation;
//	vector< Solution > selection;
//	vector< Solution > offspring;

	PopulationGenerator * generator;
	StoppingCriterion * criterio;

	vector< PopulationOperator * > operators;

public:
	Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio
	);
	~Algorithm();

	Solution lets_go();

	void addBeforeLoop( vector< PopulationOperator * > operators );
};

#endif /* ALGORITHM_H_ */
