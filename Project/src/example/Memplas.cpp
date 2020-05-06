#include "Memplas.h"

#include "../GlobalVariables.h"

#include <bits/stdc++.h>

Memplas::Memplas( double sizePlasmideo ) {
	if( sizePlasmideo < 0 ){
		throw runtime_error("SizePlasmideo must be bigger than zero.");
	}
	this->sizePlasmideo = sizePlasmideo;
	this->interation = 0;
}

Memplas::~Memplas() {
}

vector< Solution > Memplas::crossing( vector< Solution > population, vector< Solution > elite ){
	vector< Solution > offspring;
	if( this->interation % 10 != 0 ){
		offspring = this->crossover( elite );
	}else{
		offspring = this->plasmid( population, elite );
	}
	offspring = this->restoringOperations( offspring );
	return offspring;
}

vector< Solution > Memplas::plasmid( vector< Solution > population, vector< Solution > elite ){
	int numberOfSolutions = elite.size();
	int sizeSolution = -1;
	int randomNumber = -1;
	Solution sElite( GlobalVarables::instance->getNumberCities()+1 );
	Solution sNormal( GlobalVarables::instance->getNumberCities()+1 );
	Solution newSol( GlobalVarables::instance->getNumberCities()+1 );
	Solution better( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i++ ){
		sElite = elite[i];
		sNormal = population[i];
		better = Solution( GlobalVarables::instance->getNumberCities()+1 );

		sizeSolution = ( (sElite.getSize() <= sNormal.getSize()) ? sElite.getSize()-1 : sNormal.getSize()-1 );
		randomNumber = sizeSolution * this->sizePlasmideo;
		randomNumber = ( rand() % (sizeSolution-randomNumber) );

		newSol = Solution( GlobalVarables::instance->getNumberCities()+1 );

		for( int j = 0; j < sNormal.getSize(); j++ ){
			if( j == randomNumber ){
				for(int k = 0; k < this->sizePlasmideo; k++ ){
					newSol.addEnd( sElite.getCityAt( j ), sElite.getCarAt( j ) );
					j++;
				}
				j--;
			}else{
				newSol.addEnd( sNormal.getCityAt( j ), sNormal.getCarAt( j ) );
			}
		}
		offspring[i] = newSol;
	}
	return offspring;
}

vector< Solution > Memplas::crossover( vector< Solution > population ){
	int numberOfSolutions = population.size();
	int randomNumber = -1;
	Solution s1( GlobalVarables::instance->getNumberCities()+1 );
	Solution s2( GlobalVarables::instance->getNumberCities()+1 );
	Solution new1( GlobalVarables::instance->getNumberCities()+1 );
	Solution new2( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > offspring( numberOfSolutions );

	for( int i = 0; i < numberOfSolutions; i += 2 ){
		s1 = population[i];
		s2 = population[i+1];
		new1 = Solution( GlobalVarables::instance->getNumberCities()+1 );
		new2 = Solution( GlobalVarables::instance->getNumberCities()+1 );
		randomNumber = ( (s1.getSize() <= s2.getSize()) ? s1.getSize()-1 : s2.getSize()-1 );
		randomNumber = rand() % randomNumber;
		if( randomNumber == 0 ) randomNumber++;

		for( int j = 0; j < randomNumber; j++ ){
			new1.addEnd( s1.getCityAt( j ), s1.getCarAt( j ) );
			new2.addEnd( s2.getCityAt( j ), s2.getCarAt( j ) );
		}
		for( int j = randomNumber; j < s2.getSize(); j++ ){
			new1.addEnd( s2.getCityAt( j ), s2.getCarAt( j ) );
		}
		for( int j = randomNumber; j < s1.getSize(); j++ ){
			new2.addEnd( s1.getCityAt( j ), s1.getCarAt( j ) );
		}

		offspring[ i ]   = new1;
		offspring[ i+1 ] = new2;
	}

	return offspring;
}

vector< Solution > Memplas::restoringOperations( vector< Solution > population ){
	Solution sol( GlobalVarables::instance->getNumberCities()+1 );
	vector< Solution > newPopulation( population.size() );
	for( int i = 0; i < (int) population.size(); i++ ){
		sol = population[ i ];
		sol = this->removeErrors( sol );
		sol = this->insertCities( sol );
		sol = this->insertCars( sol );
		sol = this->checkQuota( sol );
		newPopulation[i] = sol;
	}
	return newPopulation;
}

Solution Memplas::removeErrors( Solution sol ){
	bool isRepeated = false;
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	int numberCars = GlobalVarables::instance->getNumberCars();
	int numberCities = GlobalVarables::instance->getNumberCities();
	usedCars.clear();
	usedCities.clear();
	Solution newSol = sol;

	for( int i = 0; i < numberCities; i++ ){
		usedCities.push_back( Pair( i, -1 ) );
	}
	for( int i = 0; i < numberCars; i++ ){
		usedCars.push_back( Pair( i, -1 ) );
	}

	for( int i = 0; i < sol.getSize(); i++ ){
		actualCar = sol.getCarAt( i );
		actualCity = sol.getCityAt( i );
		if( lastCar != actualCar && usedCars[ actualCar ].getValue() == 1 ){
			newSol.overwriteCarAt( i, -2 );
			isRepeated = true;
		} else if( usedCars[ actualCar ].getValue() == 1 && isRepeated ){
			newSol.overwriteCarAt( i, -2 );
		}else if( lastCar != actualCar ){
			usedCars[ actualCar ].plusValue();
			isRepeated = false;
		}
		if( actualCity != 0 && usedCities[ actualCity ].getValue() == 1 ){
			newSol.overwriteCityAt( i, -2 );
		}else{
			usedCities[ actualCity ].plusValue();
		}
		lastCar = actualCar;
	}
	return newSol;
}

//void printPairs( vector< Pair > values ){
//	for( int i = 0; i < (int) values.size(); i++ ){
//		std::cout <<
//			values[i].getKey() <<
//			"-" <<
//			values[i].getValue() << ", ";
//	}
//	std::cout << std::endl;
//}

Solution Memplas::insertCities( Solution sol ){
	int lastPosition = -1, aux = 0, randomNumber = 0;
	Pair pair(-1,-1);
	Solution newSol = sol;
	SortingMethods<Pair> sort;

	usedCities = sort.sort( usedCities );

	for( int i = 0; i < GlobalVarables::instance->getNumberCities(); i++ ){
		if( usedCities[i].getValue() != 0 ){
			lastPosition = i;
			break;
		}
	}
	for( int i = 0; i < lastPosition; i++ ){
		randomNumber = rand() % lastPosition;
		pair = usedCities[ i ];
		usedCities[ i ] = usedCities[ randomNumber ];
		usedCities[ randomNumber ] = pair;
	}

	aux = 0;
	for( int i = 1; i < sol.getSize(); i++ ){
		if( newSol.getCityAt( i ) == -2 ){
			if( aux == lastPosition ){
				newSol.removeIndex( i );
				i--;
			}else{
				newSol.overwriteCityAt( i, usedCities[aux].getKey() );
				usedCities[aux].plusValue();
				aux++;
			}
		}
	}
	return newSol;
}

Solution Memplas::insertCars( Solution sol ){
	int lastCar = -1;
	Solution newSol = sol;
	for( int i = 0; i < newSol.getSize(); i++ ){
		if( newSol.getCarAt( i ) == -2 ){
			newSol.overwriteCarAt( i, lastCar );
		}else{
			lastCar = newSol.getCarAt( i );
		}
	}
	return newSol;
}

Solution Memplas::checkQuota( Solution sol ){
	int selectCity = 0, biggerQuota = INT_MIN, indexBiggerCity = -1, previousCity = 0;
	Solution newSol = sol;
	if ( newSol.getSatisfaction() < GlobalVarables::instance->getMinimalSatisfaction() ){
		for( int i = 1; i < GlobalVarables::instance->getNumberCities(); i++ ){
			if( usedCities[i].getValue() == 0 &&
					GlobalVarables::instance->getBonusSatisfaction( usedCities[i].getKey() ) > biggerQuota ){
				selectCity = usedCities[i].getKey();
				biggerQuota = GlobalVarables::instance->getBonusSatisfaction( usedCities[i].getKey() );
				indexBiggerCity = i;
			}
		}

		for( int i = 1; i < newSol.getSize()-1; i++ ){
			previousCity = newSol.getCityAt( i );
			newSol.overwriteCityAt( i, selectCity );
			if ( newSol.getSatisfaction() >= GlobalVarables::instance->getMinimalSatisfaction() ){
				usedCities[indexBiggerCity].plusValue();
				usedCities[previousCity].minusValue();
				break;
			}
			newSol.overwriteCityAt( i, previousCity );
		}
	}
	while ( newSol.getSatisfaction() < GlobalVarables::instance->getMinimalSatisfaction() ){
		for( int i = 0; i < GlobalVarables::instance->getNumberCities(); i++ ){
			if( usedCities[i].getValue() == 0 ){
				selectCity = usedCities[i].getKey();
				indexBiggerCity = i;
				break;
			}
		}
		newSol.addCityAt( newSol.getSize()-1, selectCity );
		usedCities[indexBiggerCity].plusValue();

	}
	return newSol;
}
