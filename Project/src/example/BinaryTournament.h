#ifndef BINARYTOURNAMENT_H_
#define BINARYTOURNAMENT_H_

#include "../algorithm/PopulationUpdater.h"

class BinaryTournament: public PopulationUpdater {
public:
	BinaryTournament();
	virtual ~BinaryTournament();

	vector< Solution > update( vector< Solution > population, vector< Solution > offspring );
};

#endif /* BINARYTOURNAMENT_H_ */
