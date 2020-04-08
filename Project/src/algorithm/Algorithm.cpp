
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

	population = generator->createPopulation();

	while( criterio->proceed() ){

	}

	return s;
}

