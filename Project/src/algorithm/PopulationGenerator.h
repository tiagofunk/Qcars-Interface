#ifndef POPULATIONGENERATOR_H_
#define POPULATIONGENERATOR_H_

#include "../model/Solution.h"

class PopulationGenerator{
public:
	PopulationGenerator( int sizePopulation ){
		if( sizePopulation < 0 ){
			throw runtime_error("SizePopulation must be bigger than zero.");
		}
		this->sizePopulation = sizePopulation;
	}
	virtual ~PopulationGenerator(){
	}

	virtual vector<Solution> createPopulation() = 0;

protected:
	int sizePopulation;

};



#endif /* POPULATIONGENERATOR_H_ */
