#include "Validate.h"

#include <string>
#include <iostream>

#include "../GlobalVariables.h"

using namespace std;

Validate::Validate() {
}

Validate::~Validate() {
}

void Validate::verifyQuota( Solution sol ){
	if( sol.getSatisfaction() < GlobalVarables::instance->getMinimalSatisfaction() ){
		string s = "Quota value is less than the minimum allowed.\nSatisfaction of Solution: "
				+ to_string( sol.getSatisfaction() )
				+ "\tMinimal satisfaction: "
				+ to_string( GlobalVarables::instance->getMinimalSatisfaction() );
		throw runtime_error( s );
	}
}

void Validate::checkStartAndEnd( Solution sol, int finalPosition ){
	if( finalPosition == 0 ){
		string s = "Solution is null.\n";
		throw runtime_error( s );
	}
	if( finalPosition == 1 ){
		string s = "Solution has only one city.\n";
		throw runtime_error( s );
	}
	if( finalPosition == 2 ){
		string s = "Solution has only two cities.\n";
		throw runtime_error( s );
	}
	if( sol.getCityAt( 0 ) != 0 ){
		string s = "The first city in a solution must always be equal to 0.\n";
		throw runtime_error( s );
	}
	if( sol.getCityAt( finalPosition-1 ) != 0 ){
		string s = "The final city in a solution must always be equal to 0.\n";
		throw runtime_error( s );
	}
}

void Validate::checkCitiesAndCars( Solution sol, int finalPosition ){
	for( int i = 0; i < finalPosition; i++ ){
		if( sol.getCityAt( i ) < 0 || sol.getCityAt( i ) >= GlobalVarables::instance->getNumberCities() ){
			string s = "Invalid value for city: " + to_string( sol.getCityAt( i ) ) + ".\n";
			throw runtime_error( s );
		}
		if( sol.getCarAt( i ) < 0 || sol.getCarAt( i ) >= GlobalVarables::instance->getNumberCars() ){
			string s = "Invalid value for car: " + to_string( sol.getCarAt( i ) ) + ".\n";
			throw runtime_error( s );
		}
	}
}

void Validate::checkRepetition( Solution sol, int finalPosition ){
	int actualCity = -1;
	int lastCar = -1, actualCar = -1;
	int usedCars[ GlobalVarables::instance->getNumberCars() ];
	int usedCities[ GlobalVarables::instance->getNumberCities() ];

	for( int i = 0; i < GlobalVarables::instance->getNumberCars(); i++ ){
		usedCars[ i ] = 0;
	}
	for( int i = 0; i < GlobalVarables::instance->getNumberCities(); i++ ){
		usedCities[ i ] = 0;
	}

	for( int i = 0; i < finalPosition; i++ ){
		actualCar = sol.getCarAt( i );
		actualCity = sol.getCityAt( i );
		if( lastCar != actualCar && usedCars[ actualCar ] == 1 ){
			string s = "Solution is invalid: cars sequence is repeated\n";
			throw runtime_error( s );
		}else if( lastCar != actualCar ){
			usedCars[ actualCar ]++;
		}
		if( actualCity == 0 && usedCities[ 0 ] == 2 ){
			string s = "Solution is invalid: city 0 has been used more than once\n";
			throw runtime_error( s );
		}else if( actualCity != 0 && usedCities[ actualCity ] == 1 ){
			string s = "Solution is invalid: city sequence is repeated\n";
			throw runtime_error( s );
		}else{
			usedCities[ actualCity ]++;
		}
		lastCar = actualCar;
	}
}

void Validate::isOk( Solution sol ) {
	int finalPosition = sol.getSize();
	this->checkStartAndEnd( sol, finalPosition );
	this->checkCitiesAndCars( sol, finalPosition );
	this->checkRepetition( sol, finalPosition );
}

void Validate::checkPopulation( vector< Solution > population ){
	for( int i = 0; i < (int) population.size(); i++ ){
		try{
			this->isOk( population[ i ] );
			this->verifyQuota( population[i] );
		} catch (exception &e) {
			cout << "**********Error**********" << endl << i << endl <<
					e.what() <<	population[i].toString() << endl;
			exit( 1 );
		}
	}
}

bool Validate::isValid( Solution mySolution ){
	try{
		this->isOk( mySolution );
		this->verifyQuota( mySolution );
		return true;
	}catch( runtime_error &e ){
		return false;
	}
}
