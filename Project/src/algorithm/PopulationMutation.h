#ifndef POPULATIONMUTATION_H_
#define POPULATIONMUTATION_H_

#include "../model/Solution.h"

class PopulationMutation{
public:
	PopulationMutation(){}
	virtual ~PopulationMutation(){}

	virtual vector< Solution > apply( vector< Solution > population ) = 0;
};



#endif /* POPULATIONMUTATION_H_ */
