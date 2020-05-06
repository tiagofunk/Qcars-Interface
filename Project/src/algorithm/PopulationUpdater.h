#ifndef POPULATIONUPDATER_H_
#define POPULATIONUPDATER_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationUpdater{
public:
	PopulationUpdater(){}
	virtual ~PopulationUpdater(){}

	virtual vector< Solution > update( vector< Solution > population, vector< Solution > offspring ) = 0;
};


#endif /* POPULATIONUPDATER_H_ */
