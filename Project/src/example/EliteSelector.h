#ifndef ELITESELECTOR_H_
#define ELITESELECTOR_H_

#include "../algorithm/PopulationSelector.h"

class EliteSelector: public PopulationSelector{
public:
	EliteSelector( double ratio );
	virtual ~EliteSelector();

	vector<Solution> select( vector< Solution > population );
};

#endif /* ELITESELECTOR_H_ */
