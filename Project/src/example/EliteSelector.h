#ifndef ELITESELECTOR_H_
#define ELITESELECTOR_H_

#include "../algorithm/PopulationSelector.h"

class EliteSelector: public PopulationSelector{
public:
	EliteSelector( double ratio, double cross );
	virtual ~EliteSelector();

	vector<Solution> select( vector< Solution > population );

private:
	double cross;
	int interation;
};

#endif /* ELITESELECTOR_H_ */
