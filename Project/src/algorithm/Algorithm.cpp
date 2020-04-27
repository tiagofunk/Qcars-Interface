
#include "Algorithm.h"

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio,
		PopulationSelector * elite,
		PopulationCrossing * crossing
	){
	this->generator = generator;
	this->criterio = criterio;
	this->elite = elite;
	this->crossing = crossing;
}

Algorithm::~Algorithm(){
	delete this->generator;
	delete this->criterio;
	delete this->elite;
	delete this->crossing;
}

Solution Algorithm::lets_go(){
	Solution s;

	this->population = this->generator->createPopulation();

	for( PopulationOperator * op: this->operatorsBeforeLoop ){
		this->population = op->operate( this->population );
	}

	while( this->criterio->proceed() ){
		this->elitePopulation = this->elite->select( this->population );

		this->offspring = this->crossing->crossing( this->population, this->elitePopulation );

	}

	return s;
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operatorsBeforeLoop = operators;
}
