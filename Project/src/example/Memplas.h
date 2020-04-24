#ifndef MEMPLAS_H_
#define MEMPLAS_H_

#include "../algorithm/PopulationCrossing.h"

class Memplas: public PopulationCrossing {
public:
	Memplas( int sizePlasmideo );
	virtual ~Memplas();

	vector< Solution > crossing( vector< Solution > population, vector< Solution > elite );

private:
	int sizePlasmideo;
	int interation;

	vector< Solution > plasmid( vector< Solution > population, int sizePlasmideo, vector< Solution > elite );
	vector< Solution > crossover( vector< Solution > population );
	vector< Solution > restoringOperations( vector< Solution > population );
};

#endif /* MEMPLAS_H_ */
