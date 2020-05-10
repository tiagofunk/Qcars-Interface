#ifndef PATHRELINKING_H_
#define PATHRELINKING_H_

#include <string>

#include "../algorithm/PopulationOperator.h"

using namespace std;

class PathRelinking: public PopulationOperator {
public:
	PathRelinking( string selectionStrategy, string intermediaryStrategy );
	virtual ~PathRelinking();

	vector< Solution > operate( vector< Solution > population );

private:
	string selectionStrategy;
	string intermediaryStrategy;

	Solution selector( Solution s1, Solution s2, string intermediaryStrategy, bool foward );

	Solution startToEnd( Solution initial, Solution goal );
	Solution endToStart( Solution initial, Solution goal );
	Solution random( Solution initial, Solution goal );

	const string START_TO_END_FOWARD = "stef";
	const string START_TO_END_BACKWARD = "steb";

	const string END_TO_START_FOWARD = "etsf";
	const string END_TO_START_BACKWARD = "etsb";

	const string RANDOM_FOWARD = "rf";
	const string RANDOM_BACKWARD = "rb";
};

#endif /* PATHRELINKING_H_ */
