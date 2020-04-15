#include "MultiOperatorsLocalSearch.h"
#include "../model/Solution.h"
#include "../GlobalVariables.h"

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

MultiOperatorsLocalSearch::MultiOperatorsLocalSearch() {
}

MultiOperatorsLocalSearch::~MultiOperatorsLocalSearch() {
}

vector< Solution > MultiOperatorsLocalSearch::operate( vector< Solution > population ){
	vector< Solution > sol = population;
	sol = removeSaving( sol );
	sol = invertSolution( sol );
	sol = insertSavingCity( sol );
	sol = replaceSavingCity( sol );
	sol = replaceSavingCar( sol );
	sol = operator_2opt( sol );
	return sol;
}

vector< Solution > MultiOperatorsLocalSearch::removeSaving( vector< Solution > population ){
	bool go_ahead;
		int posMin, minCitySatisfaction;
		Solution son( GlobalVarables::instance->getNumberCities()+1 );
		Solution dad( GlobalVarables::instance->getNumberCities()+1 );
		vector< Solution > newPopulation( population.size() );

		for( int i = 0; i < (int) population.size(); i++ ){
			go_ahead = true;
			son = population[i];
			dad = son;

			while( go_ahead ){
				posMin = -1;
				minCitySatisfaction = INT_MAX;

				for( int j = 1; j < son.getQtyCity()-1; j++ ){
					if( GlobalVarables::instance->getBonusSatisfaction( son.getCityAt( j ) ) < minCitySatisfaction ){
						minCitySatisfaction = GlobalVarables::instance->getBonusSatisfaction( son.getCityAt( j ) );
						posMin = j;
					}
				}

				if( (son.getSatisfaction() - minCitySatisfaction)
							< GlobalVarables::instance->getMinimalSatisfaction() ){
					go_ahead = false;
				}else {
					son.removeIndex( posMin );
				}
			}

			if( son.getFitness() < dad.getFitness() ){
				newPopulation[i] = son;
			}else{
				newPopulation[i] = dad;
			}
		}
		return newPopulation;
}

vector< Solution > MultiOperatorsLocalSearch::invertSolution( vector< Solution > population ){
	Solution son( GlobalVarables::instance->getNumberCities()+1 );
	Solution dad( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		dad = population[ i ];
		son = Solution( dad.getSize() );

		for( int j = dad.getSize()-1; j >= 0; j-- ){
			if( dad.getCarAt( j ) != dad.getCarAt( j-1 ) && j != 0 ){
				son.addEnd( dad.getCarAt( j ), dad.getCarAt( j-1 ) );
			}else{
				son.addEnd( dad.getCarAt( j ), dad.getCarAt( j ) );
			}
		}

		if( son.getFitness() < dad.getFitness() ){
			newPopulation[i] = son;
		}else{
			newPopulation[i] = dad;
		}
	}
	return newPopulation;
}

vector< Solution > MultiOperatorsLocalSearch::insertSavingCity( vector< Solution > population ){
	bool visitedCities[ GlobalVarables::instance->getNumberCities() ];
	Solution son( GlobalVarables::instance->getNumberCities()+1 );
	Solution better( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ];
		better = son;

		for( int j = 0; j < GlobalVarables::instance->getNumberCities(); j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son.getSize(); j++ ){
			visitedCities[ son.getCityAt( j ) ] = true;
		}
		for( int j = 0; j < GlobalVarables::instance->getNumberCities(); j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son.getSize()-1; k++ ){
					son.addCityAt( k, j );

					if( son.getSatisfaction() >= GlobalVarables::instance->getMinimalSatisfaction() ){
						if( son.getFitness() < better.getFitness() ){
							better = son;
						}
					}
					son.removeIndex( k );
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > MultiOperatorsLocalSearch::replaceSavingCity( vector< Solution > population ){
	int oldCity = -1;
	bool visitedCities[ GlobalVarables::instance->getNumberCities() ];
	Solution son( GlobalVarables::instance->getNumberCities()+1 );
	Solution better( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		son = population[ i ];
		better = son;

		for( int j = 0; j < GlobalVarables::instance->getNumberCities(); j++ ){
			visitedCities[ j ] = false;
		}
		for( int j = 0; j < son.getSize(); j++ ){
			visitedCities[ son.getCityAt( j ) ] = true;
		}
		for( int j = 0; j < GlobalVarables::instance->getNumberCities(); j++ ){
			if( !visitedCities[ j ] ){

				for( int k = 1; k < son.getSize()-1; k++ ){
					oldCity = son.getCityAt( k );
					son.overwriteCityAt( k, j );

					if( son.getSatisfaction() >= GlobalVarables::instance->getMinimalSatisfaction() ){
						if( son.getFitness() < better.getFitness() ){
							better = son;
						}
					}
					son.overwriteCityAt( k, oldCity );
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > MultiOperatorsLocalSearch::replaceSavingCar( vector< Solution > population ){
	bool usedCars[ GlobalVarables::instance->getNumberCities() ];
	Solution better( GlobalVarables::instance->getNumberCities()+1 );
	Solution actual( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		better = population[ i ];
		actual = better;

		for( int j = 0; j < GlobalVarables::instance->getNumberCars(); j++ ){
			usedCars[ j ] = false;
		}
		for( int j = 0; j < actual.getSize(); j++ ){
			usedCars[ actual.getCarAt( j ) ] = true;
		}
		for( int j = 0; j < GlobalVarables::instance->getNumberCars(); j++ ){
			if( !usedCars[ j ] ){

				for( int k = 0; k < actual.getSize(); k++ ){
					actual.overwriteCarAt( k, j );
					usedCars[j] = true;

					if( actual.getSatisfaction() >= GlobalVarables::instance->getMinimalSatisfaction() ){
						if( actual.getFitness() < better.getFitness() ){
							better = actual;
						}
					}
				}
			}
		}
		newPopulation[i] = better;
	}
	return newPopulation;
}

vector< Solution > MultiOperatorsLocalSearch::operator_2opt( vector< Solution > population ){
	Solution backup( GlobalVarables::instance->getNumberCities()+1 );
	Solution better( GlobalVarables::instance->getNumberCities()+1 );
	Solution actual( GlobalVarables::instance->getNumberCities()+1 );
	vector< int > myVector( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );

	for( int i = 0; i < (int) population.size(); i++ ){
		actual = population[ i ];
		better = actual;
		backup = actual;

		for( int j = 1; j < actual.getSize()-2; j++ ){
			myVector.clear();

			myVector.push_back( actual.getCityAt( 0 ) );
			for( int k = j+1; k < actual.getSize()-1; k++ ){
				myVector.push_back(  actual.getCityAt( k ) );
			}

			for( int k = 1; k <= j; k++ ){
				myVector.push_back( actual.getCityAt( k ) );
			}

			myVector.push_back( actual.getCityAt( actual.getSize()-1 ) );
			myVector.push_back( actual.getCityAt( actual.getSize() ) );
			for( int i = 0; i < (int) myVector.size(); i++ ){
				actual.overwriteCityAt( i, myVector[ i ] );
			}

			if( actual.getFitness() < better.getFitness() ){
				better = actual;
			}
			actual = backup;
		}
		newPopulation[ i ] = better;
	}
	return newPopulation;
}
