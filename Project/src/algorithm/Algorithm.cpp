
#include "Algorithm.h"

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio
	){
	this->generator = generator;
	this->criterio = criterio;
}

Algorithm::~Algorithm(){
	delete generator;
	delete criterio;
}

Solution Algorithm::lets_go(){
	Solution s;

	this->population = this->generator->createPopulation();

	for( PopulationOperator * op: this->operators ){
		this->population = op->operate( this->population );
	}

	while( this->criterio->proceed() ){

	}

	return s;
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operators = operators;
}
