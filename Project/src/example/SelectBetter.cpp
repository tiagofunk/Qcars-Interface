#include "SelectBetter.h"

#include "../utils/SortingMethods.h"

SelectBetter::SelectBetter() {
}

SelectBetter::~SelectBetter() {
}

vector<Solution> SelectBetter::select( vector< Solution > population ){
	SortingMethods< Solution > sort;
	population = sort.sort( population );
	vector< Solution > newPopulation;
	newPopulation.push_back( population.at( 0 ) );
	return newPopulation;
}
