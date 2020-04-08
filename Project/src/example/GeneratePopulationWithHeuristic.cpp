#include <bits/stdc++.h>
#include <stdlib.h>

#include "GeneratePopulationWithHeuristic.h"

GeneratePopulationWithHeuristic::GeneratePopulationWithHeuristic( int size) {

}

GeneratePopulationWithHeuristic::~GeneratePopulationWithHeuristic(){
	delete instance;
}


vector< int > GeneratePopulationWithHeuristic::initAndShuffle( int vectorSize, bool hasCities ){
	int aux = 0;
	int number = 0;
	vector< int > myVector( hasCities ? vectorSize-1 : vectorSize );

	for( int i = 0; (int) myVector.size(); i++ ){
		if( hasCities){
			myVector[ i ] = i+1;
		}else{
			myVector[ i ] = i;
		}
	}
	for( int i = 0; (int) myVector.size(); i++ ){
		number = rand() % myVector.size();
		aux = myVector[ i ];
		myVector[ i ] = myVector[ number ];
		myVector[ number ] = aux;
	}


	return myVector;
}

int GeneratePopulationWithHeuristic::selectCityWithHeuristic(int car, int cityInit, vector< int > citiesNotVisited ){
	int value, min = INT_MAX, pos = 0;
	for( int i = 0; i < (int) citiesNotVisited.size(); i++ ){
		value = this->instance->getCar(car).getEdgeWeigth( cityInit, citiesNotVisited[ i ] );
		if( min > value && value != 0 ){
			min = value;
			pos = i;
		}
	}
	return pos;
}
