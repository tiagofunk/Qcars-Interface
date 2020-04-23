#include "EliteSelector.h"
#include "../utils/SortingMethods.h"

EliteSelector::EliteSelector( double ratio ): PopulationSelector( ratio ) {
}

EliteSelector::~EliteSelector() {
}

vector<Solution> EliteSelector::select( vector< Solution > population ){
	int numberOfSolutions = population.size() * this->ratio;
	if( numberOfSolutions % 2 == 1 || numberOfSolutions == 0 ){
		numberOfSolutions++;
	}
	vector< Solution > elite( numberOfSolutions );
	SortingMethods<Solution> sm;
	population = sm.sort( population );
	for( int i = 0; i < numberOfSolutions; i++ ){
		elite[ i ] = population[ i ];
	}
	return elite;
}
