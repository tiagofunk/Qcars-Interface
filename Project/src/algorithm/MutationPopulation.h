#ifndef MUTATIONPOPULATION_H_
#define MUTATIONPOPULATION_H_

#include "../model/Solution.h"

class MutationPopulation{
public:
	virtual vector< Solution > apply() = 0;
};



#endif /* MUTATIONPOPULATION_H_ */
