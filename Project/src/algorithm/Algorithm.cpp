#include "Algorithm.h"

#include <iostream>

Algorithm::Algorithm(
		PopulationGenerator * generator,
		StoppingCriterion * criterio,
		PopulationSelector * elite,
		PopulationCrossing * crossing,
		PopulationMutation * mult
	){
	this->generator = generator;
	this->criterio = criterio;
	this->elite = elite;
	this->crossing = crossing;
	this->mult = mult;
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
		std::cout << "select" << std::endl;
		for( Solution s: this->elitePopulation ){
			std::cout << s.toString() << std::endl << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		this->offspring = this->crossing->crossing( this->population, this->elitePopulation );
		std::cout << "crossing" << std::endl;
		for( Solution s: this->offspring ){
			std::cout << s.toString() << std::endl << std::endl;
		}
		std::cout << "**************************************" << std::endl;


		this->offspring = this->mult->apply( this->offspring );
		std::cout << "apply" << std::endl;
		for( Solution s: this->offspring ){
			std::cout << s.toString() << std::endl << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		for( PopulationOperator * op: this->operatorsBeforeLoop ){
			this->offspring = op->operate( this->offspring );
		}
	}

	return s;
}

void Algorithm::addBeforeLoop( vector< PopulationOperator * > operators ){
	this->operatorsBeforeLoop = operators;
}

void Algorithm::addOnLoop( vector< PopulationOperator * > operators ){
	this->operatorsOnLoop = operators;
}
