#ifndef GENERATEPOPULATIONWITHHEURISTIC_H_
#define GENERATEPOPULATIONWITHHEURISTIC_H_

#include <vector>

#include "../model/Instance.h"

using namespace std;

class GeneratePopulationWithHeuristic {
public:
	GeneratePopulationWithHeuristic( int size );
	~GeneratePopulationWithHeuristic();

private:
	vector< int > initAndShuffle( int vectorSize, bool hasCities );
	int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited );

	Instance * instance = 0;

};

#endif /* GENERATEPOPULATIONWITHHEURISTIC_H_ */
