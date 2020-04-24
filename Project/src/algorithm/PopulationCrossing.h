#ifndef POPULATIONCROSSING_H_
#define POPULATIONCROSSING_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationCrossing{
public:
	PopulationCrossing(){}
	virtual ~PopulationCrossing(){}

	virtual vector< Solution > crossing( vector< Solution > population, vector< Solution > elite ) = 0;

private:

};



#endif /* POPULATIONCROSSING_H_ */
