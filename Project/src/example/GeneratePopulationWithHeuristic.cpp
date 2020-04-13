#include <bits/stdc++.h>
#include <stdlib.h>

#include "GeneratePopulationWithHeuristic.h"

GeneratePopulationWithHeuristic::GeneratePopulationWithHeuristic( int sizePopulation )
	: PopulationGenerator( sizePopulation ){
}

GeneratePopulationWithHeuristic::~GeneratePopulationWithHeuristic(){
}

vector<Solution> GeneratePopulationWithHeuristic::createPopulation(){
	bool firstCity;
	int pos;
	int myCar, destinyCity, nextCity;
	Solution mySolution( GlobalVarables::instance->getNumberCities()+1 );
	vector< int > carsNotUsed;
	vector< int > citiesNotVisited;
	vector< Solution > population( this->sizePopulation );

	for( int i = 0; i < this->sizePopulation; i++ ){
		firstCity = true;
		carsNotUsed = initAndShuffle( GlobalVarables::instance->getNumberCars(), false );
		citiesNotVisited = initAndShuffle( GlobalVarables::instance->getNumberCities(), true );
		mySolution = Solution( GlobalVarables::instance->getNumberCities()+1 );

		do{
			myCar = carsNotUsed[ 0 ];
			if( carsNotUsed.size() != 1 ){
				carsNotUsed.erase( carsNotUsed.begin() + 0 );
			}

			destinyCity = citiesNotVisited[ 0 ];

			do{
				if( firstCity ){
					nextCity = 0;
					firstCity = false;
				}else{
					pos = selectCityWithHeuristic( myCar, nextCity, citiesNotVisited );
					nextCity = citiesNotVisited[ pos ];
					citiesNotVisited.erase( citiesNotVisited.begin() + pos );
				}
				mySolution.addEnd( nextCity, myCar );
			}while( destinyCity != nextCity );

		}while( mySolution.getSatisfaction() < GlobalVarables::instance->getMinimalSatisfaction() );

		mySolution.addEnd( 0, myCar );

		population[ i ] = mySolution;
	}
	return population;
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
	Car c = GlobalVarables::instance->getCar( car );
	for( int i = 0; i < (int) citiesNotVisited.size(); i++ ){
		value = c.getEdgeWeigth( cityInit, citiesNotVisited[ i ] );
		if( min > value && value != 0 ){
			min = value;
			pos = i;
		}
	}
	return pos;
}
