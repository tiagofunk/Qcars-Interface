
#include "Algorithm.h"

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio,
		PopulationSelector * elite
	){
	this->generator = generator;
	this->criterio = criterio;
	this->elite = elite;
}

Algorithm::~Algorithm(){
	delete generator;
	delete criterio;
	delete elite;
}

Solution Algorithm::lets_go(){
	Solution s;

	this->population = this->generator->createPopulation();

	for( PopulationOperator * op: this->operatorsBeforeLoop ){
		this->population = op->operate( this->population );
	}

	while( this->criterio->proceed() ){
		elitePopulation = this->elite->select( this->population );

	}

	return s;
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operatorsBeforeLoop = operators;
}
