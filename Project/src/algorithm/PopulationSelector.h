#ifndef POPULATIONSELECTOR_H_
#define POPULATIONSELECTOR_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationSelector{
public:
	PopulationSelector( double ratio ){
		this->ratio = 0.0;
	}
	virtual ~PopulationSelector(){}

	virtual vector<Solution> select( vector< Solution > population ) = 0;

protected:
	double ratio;
};

#endif /* POPULATIONSELECTOR_H_ */
