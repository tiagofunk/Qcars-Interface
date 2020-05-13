#ifndef SELECTBETTER_H_
#define SELECTBETTER_H_

#include <vector>

#include "../model/Solution.h"
#include "../algorithm/PopulationSelector.h"

using namespace std;
class SelectBetter : public PopulationSelector{
public:
	SelectBetter();
	virtual ~SelectBetter();

	vector<Solution> select( vector< Solution > population );
};

#endif /* SELECTBETTER_H_ */
