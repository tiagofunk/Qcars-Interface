#ifndef POPULATIONGENERATOR_H_
#define POPULATIONGENERATOR_H_

#include "../model/Solution.h"

class PopulationGenerator{
public:
	PopulationGenerator( int sizePopulation ){
		this->sizePopulation = sizePopulation;
	}

	virtual vector<Solution> createPopulation() = 0;

private:
	int sizePopulation;

};



#endif /* POPULATIONGENERATOR_H_ */
