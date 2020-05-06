#include "Algorithm.h"

#include <iostream>

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion   * criterio,
		PopulationSelector  * elite,
		PopulationCrossing  * crossing,
		PopulationMutation  * mult,
		PopulationUpdater   * upd
	){
	this->generator = generator;
	this->criterio = criterio;
	this->elite = elite;
	this->crossing = crossing;
	this->mult = mult;
	this->upd = upd;
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

		this->offspring = this->mult->apply( this->offspring );

		for( PopulationOperator * op: this->operatorsOnLoop ){
			this->offspring = op->operate( this->offspring );
		}

		this->population = this->upd->update( this->population, this->offspring );

	}

	std::cout << "population" << std::endl;
	for( Solution s: this->population ){
		std::cout << s.toString() << std::endl << std::endl;
	}
	std::cout << "**************************************" << std::endl;

	return s;
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operatorsBeforeLoop = operators;
}

void Algorithm::addOnLoop( vector< PopulationOperator * > operators ){
	this->operatorsOnLoop = operators;
}
