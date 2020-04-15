#ifndef MULTIOPERATORSLOCALSEARCH_H_
#define MULTIOPERATORSLOCALSEARCH_H_

#include "../algorithm/PopulationOperator.h"

class MultiOperatorsLocalSearch: public PopulationOperator {
public:
	MultiOperatorsLocalSearch();
	virtual ~MultiOperatorsLocalSearch();

	vector< Solution > operate( vector< Solution > population );

private:
	vector< Solution > removeSaving( vector< Solution > population );
	vector< Solution > invertSolution( vector< Solution > population );
	vector< Solution > insertSavingCity( vector< Solution > population );
	vector< Solution > replaceSavingCity( vector< Solution > population );
	vector< Solution > replaceSavingCar( vector< Solution > population );
	vector< Solution > operator_2opt( vector< Solution > population );
};

#endif /* MULTIOPERATORSLOCALSEARCH_H_ */
