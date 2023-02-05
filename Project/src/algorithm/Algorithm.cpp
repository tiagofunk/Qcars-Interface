#include "Algorithm.h"

#include <iostream>

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion   * criterio,
		PopulationSelector  * elite,
		PopulationCrossing  * crossing,
		PopulationMutation  * multation,
		PopulationUpdater   * updater,
		PopulationSelector  * selBetter
	){
	this->generator = generator;
	this->criterio = criterio;
	this->elite = elite;
	this->crossing = crossing;
	this->multation = multation;
	this->updater = updater;
	this->selBetter = selBetter;
}

Algorithm::~Algorithm(){
	delete this->generator;
	delete this->criterio;
	delete this->elite;
	delete this->crossing;
	delete this->multation;
	delete this->updater;
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

		this->offspring = this->multation->apply( this->offspring );

		for( PopulationOperator * op: this->operatorsOnLoop ){
			this->offspring = op->operate( this->offspring );
		}

		this->population = this->updater->update( this->population, this->offspring );

	}

	return selBetter->select( this->population ).at( 0 );
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operatorsBeforeLoop = operators;
}

void Algorithm::addOnLoop( vector< PopulationOperator * > operators ){
	this->operatorsOnLoop = operators;
}
