
#include "Algorithm.h"

Algorithm::Algorithm(
		string strategy,
		int sizePopulation,
		double elite,
		int limitIterations,
		double sizePlasmideo,
		double cross,
		string selectionStrategy,
		string intermediaryStrategy
	){

	this->strategy = strategy;
	this->sizePopulation = sizePopulation;
	this->elite = elite;
	this->limitIterations = limitIterations;
	this->sizePlasmideo = sizePlasmideo;
	this->cross = cross;
	this->selectionStrategy = selectionStrategy;
	this->intermediaryStrategy = intermediaryStrategy;

}


