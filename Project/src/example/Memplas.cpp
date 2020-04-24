
#include "Memplas.h"

Memplas::Memplas( int sizePlasmideo ) {
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
		offspring = this->plasmid( population, this->sizePlasmideo, elite );
	}
	offspring = this->restoringOperations( offspring );
	return offspring;
}

vector< Solution > Memplas::plasmid( vector< Solution > population, int sizePlasmideo, vector< Solution > elite ){
	return population;
}

vector< Solution > Memplas::crossover( vector< Solution > population ){
	return population;
}

vector< Solution > Memplas::restoringOperations( vector< Solution > population ){
	return population;
}
