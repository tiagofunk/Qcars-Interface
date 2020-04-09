#ifndef GENERATEPOPULATIONWITHHEURISTIC_H_
#define GENERATEPOPULATIONWITHHEURISTIC_H_

#include <vector>

#include "../model/Instance.h"
#include "../model/Solution.h"
#include "../algorithm/PopulationGenerator.h"

using namespace std;

class GeneratePopulationWithHeuristic: PopulationGenerator {
public:
	GeneratePopulationWithHeuristic( int sizePopulation, Instance * instance );
	~GeneratePopulationWithHeuristic();

	vector<Solution> createPopulation();

private:
	Instance * instance = 0;

	vector< int > initAndShuffle( int vectorSize, bool hasCities );
	int selectCityWithHeuristic( int car, int cityInit, vector< int > citiesNotVisited );

};

#endif /* GENERATEPOPULATIONWITHHEURISTIC_H_ */
