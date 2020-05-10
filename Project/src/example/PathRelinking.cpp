#include "PathRelinking.h"
#include "../GlobalVariables.h"
#include "../utils/SortingMethods.h"
#include "../utils/Validate.h"

PathRelinking::PathRelinking( string selectionStrategy, string intermediaryStrategy ) {
	this->selectionStrategy = selectionStrategy;
	this->intermediaryStrategy = intermediaryStrategy;
}

PathRelinking::~PathRelinking() {
}

vector< Solution > PathRelinking::operate( vector< Solution > population ){
	bool foward = intermediaryStrategy == this->START_TO_END_FOWARD
			|| intermediaryStrategy == this->END_TO_START_FOWARD
			|| intermediaryStrategy == this->RANDOM_FOWARD;
	Solution newSolution( GlobalVarables::instance->getNumberCities()+1 );

	SortingMethods<Solution> sort;
	vector<Solution> elite = sort.sort( population );
	for( unsigned int i = 1; i < elite.size(); i++ ){
		newSolution = selector( elite[0], elite[i], intermediaryStrategy, foward );
		for( unsigned int j = 0; j < elite.size(); j++ ){
			int a = elite[j].getFitness();
			int b = newSolution.getFitness();
			if( a > b ){
				elite[i] = newSolution;
				break;
			}
		}
	}
	return elite;
}

Solution PathRelinking::selector( Solution s1, Solution s2, string intermediaryStrategy, bool foward ){
	Solution newSolution( GlobalVarables::instance->getNumberCities()+1 );
	if( intermediaryStrategy == this->START_TO_END_FOWARD
			|| intermediaryStrategy == this->START_TO_END_BACKWARD){
		if( foward ){
			newSolution = startToEnd( s1, s2 );
		}else{
			newSolution = startToEnd( s2, s1 );
		}
	}else if( intermediaryStrategy == this->END_TO_START_FOWARD
			|| intermediaryStrategy == this->END_TO_START_BACKWARD ){
		if( foward ){
			newSolution = endToStart( s1, s2 );
		}else{
			newSolution = endToStart( s2, s1 );
		}
	}else if( intermediaryStrategy == this->RANDOM_FOWARD
			|| intermediaryStrategy == this->RANDOM_BACKWARD){
		if( foward ){
			newSolution = random( s1, s2 );
		}else{
			newSolution = random( s2, s1 );
		}
	}
	return newSolution;
}

Solution PathRelinking::startToEnd( Solution initial, Solution goal ){
	Solution better = goal;
	Validate val;

	if( initial.getFitness() < goal.getFitness() ){
		better = initial;
	}

	for( int i = 0; i < initial.getSize(); i++ ){

		if( i < goal.getSize()-1 ){
			goal.overwriteCityAt( i, initial.getCityAt( i ) );
			goal.overwriteCarAt( i, initial.getCarAt( i ) );
		}else{
			goal.addCityAndCarAt( i, initial.getCityAt( i ), initial.getCarAt( i ) );
		}

		if( val.isValid( goal ) ){

			if( goal.getFitness() >= GlobalVarables::instance->getMinimalSatisfaction() &&
					goal.getFitness() < better.getFitness() ){
				better = goal;
			}
		}
	}
	return better;
}

Solution PathRelinking::endToStart( Solution initial, Solution goal ){
	int size = initial.getSize() <= goal.getSize() ? initial.getSize() : goal.getSize();
		Solution better = goal;
		Validate val;

		if( initial.getFitness() < goal.getFitness() ){
			better = initial;
		}else{
			better = goal;
		}

		for( int i =size-1; i >= 0; i-- ){

			if( i < goal.getSize()-1 ){
				goal.overwriteCityAt( i, initial.getCityAt( i ) );
				goal.overwriteCarAt( i, initial.getCarAt( i ) );
			}else{
				goal.addCityAndCarAt( i, initial.getCityAt( i ), initial.getCarAt( i ) );
			}

			if( val.isValid( goal ) ){

				if( goal.getFitness() >= GlobalVarables::instance->getMinimalSatisfaction() &&
						goal.getFitness() < better.getFitness() ){
					better = goal;
				}
			}
		}
		return better;
}

Solution PathRelinking::random( Solution initial, Solution goal ){
	int size = initial.getSize() <= goal.getSize() ? initial.getSize() : goal.getSize();
		int aux = 0, randomNumber = 0;
		int indexes[ size ];
		Solution better = goal;
		Validate val;

		if( initial.getFitness() < goal.getFitness() ){
			better = initial;
		}else{
			better = goal;
		}

		for( int i = 0; i < size; i++ ){
			indexes[i] = i;
		}
		for( int i = 0; i < size; i++ ){
			randomNumber = rand() % size;
			aux = indexes[ randomNumber ];
			indexes[ randomNumber ] = indexes[ i ];
			indexes[ i ] = aux;
		}

		for( int i = 0; i < size; i++ ){

			if( indexes[ i ] < goal.getSize()-1 ){
				goal.overwriteCityAt( indexes[ i ], initial.getCityAt( indexes[ i ] ) );
				goal.overwriteCarAt( indexes[ i ], initial.getCarAt( indexes[ i ] ) );
			}else{
				goal.addCityAndCarAt( indexes[ i ], initial.getCityAt( i ), initial.getCarAt( indexes[ i ] ) );
			}

			if( val.isValid( goal ) ){

				if( goal.getFitness() >= GlobalVarables::instance->getMinimalSatisfaction() &&
						goal.getFitness() < better.getFitness() ){
					better = goal;
				}
			}
		}
		return better;
}
