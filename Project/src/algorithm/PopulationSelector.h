#ifndef POPULATIONSELECTOR_H_
#define POPULATIONSELECTOR_H_

#include <vector>
#include <string.h>

#include "../model/Solution.h"

using namespace std;

class PopulationSelector{
public:
	PopulationSelector( double ratio ){
		if( ratio < 0.0 || ratio > 1.0 ){
			throw runtime_error("ratio value must be between 0.0 and 1.0: ratio=" + to_string( ratio ) );
		}
		this->ratio = ratio;
	}
	virtual ~PopulationSelector(){}

	virtual vector<Solution> select( vector< Solution > population ) = 0;

protected:
	double ratio;
};

#endif /* POPULATIONSELECTOR_H_ */
