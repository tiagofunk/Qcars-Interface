#ifndef POPULATIONOPERATOR_H_
#define POPULATIONOPERATOR_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationOperator {
public:
	PopulationOperator(){}
	virtual ~PopulationOperator(){}

	virtual vector< Solution > operate( vector< Solution > population ) = 0;
};

#endif /* POPULATIONOPERATOR_H_ */
