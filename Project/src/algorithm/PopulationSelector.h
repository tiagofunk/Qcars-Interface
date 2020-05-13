#ifndef POPULATIONSELECTOR_H_
#define POPULATIONSELECTOR_H_

#include <vector>
#include <string.h>

#include "../model/Solution.h"

using namespace std;

class PopulationSelector{
public:
	PopulationSelector(){}
	virtual ~PopulationSelector(){}

	virtual vector<Solution> select( vector< Solution > population ) = 0;

};

#endif /* POPULATIONSELECTOR_H_ */
