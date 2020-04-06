#ifndef POPULATIONCROSSING_H_
#define POPULATIONCROSSING_H_

#include <vector>

#include "../model/Solution.h"

using namespace std;

class PopulationCrossing{
public:

	virtual vector< Solution > crossing() = 0;

private:

};



#endif /* POPULATIONCROSSING_H_ */
