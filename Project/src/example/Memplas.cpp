#include "Memplas.h"

#include "../GlobalVariables.h"

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
	return sol;
}

Solution Memplas::insertCities( Solution sol ){
	return sol;
}

Solution Memplas::insertCars( Solution sol ){
	return sol;
}

Solution Memplas::checkQuota( Solution sol ){
	return sol;
}
