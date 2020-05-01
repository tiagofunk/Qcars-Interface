#ifndef EMPTYMUTATION_H_
#define EMPTYMUTATION_H_

#include "../algorithm/PopulationMutation.h"

class EmptyMutation: public PopulationMutation {
public:
	EmptyMutation();
	virtual ~EmptyMutation();

	vector< Solution > apply( vector< Solution > population );
};

#endif /* EMPTYMUTATION_H_ */
