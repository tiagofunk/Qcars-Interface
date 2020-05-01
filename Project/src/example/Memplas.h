#ifndef MEMPLAS_H_
#define MEMPLAS_H_

#include "../algorithm/PopulationCrossing.h"
#include "../model/Pair.h"
#include "../utils/SortingMethods.h"

class Memplas: public PopulationCrossing {
public:
	Memplas( double sizePlasmideo );
	virtual ~Memplas();

	vector< Solution > crossing( vector< Solution > population, vector< Solution > elite );

private:
	double sizePlasmideo;
	int interation;

	vector< Pair > usedCars;
	vector< Pair > usedCities;

	vector< Solution > plasmid( vector< Solution > population, vector< Solution > elite );
	vector< Solution > crossover( vector< Solution > population );

	vector< Solution > restoringOperations( vector< Solution > population );
	Solution removeErrors( Solution sol );
	Solution insertCities( Solution sol );
	Solution insertCars( Solution sol );
	Solution checkQuota( Solution sol );
};

#endif /* MEMPLAS_H_ */
