#include "Solution.h"
#include "../GlobalVariables.h"

Solution::Solution() {
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
	this->size = 0;
	this->maxSize = 0;
	this->satisfaction = 0;
	this->fitness = 0;
}

Solution::Solution( int maxSizeSolution ){
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
	this->size = 0;
	this->satisfaction = 0;
	this->fitness = 0;

	this->maxSize = maxSizeSolution;
	this->cities.reserve( maxSizeSolution );
	this->cars.reserve( maxSizeSolution );
}

Solution::~Solution() {
}

void Solution::calculeFitness(){
	if( !this->calculatedFitness ){
		this->fitness = 0;
		int previous_car = 0, actual_car = 0;
		int rent_city = 0, actual_city = 0;
		int weigth = 0, rate = 0;
		Car myCar( 0 );

		rent_city = this->cities[ 0 ];
		previous_car = this->cars[ 0 ];
		for( int i = 0; i < this->size-1; i++ ){
			actual_city = this->cities[ i ];
			actual_car = this->cars[ i ];
			myCar = GlobalVarables::instance->getCar( actual_car );

			weigth = myCar.getEdgeWeigth( actual_city, this->cities[ i+1 ] );
			this->fitness += weigth;
			if( previous_car != actual_car ){
				myCar = GlobalVarables::instance->getCar( previous_car );
				rate = myCar.getReturnRate( rent_city, actual_car );
				this->fitness += rate;
				previous_car = actual_car;
				rent_city = actual_car;
			}
		}

		myCar = GlobalVarables::instance->getCar( previous_car );
		rate = myCar.getReturnRate( rent_city, 0 );
		this->fitness += rate;
		this->calculatedFitness = true;
	}
}

void Solution::calculeSatisfaction(){
	this->satisfaction = 0;
	for( int i = 0; i < this->size; i++ ){
		if( i != this->size-1 || (i == this->size-1 && this->cities[ i ] != 0 ) ){
			this->satisfaction += GlobalVarables::instance->getBonusSatisfaction( cities[ i ] );
		}
	}
}

void Solution::addEnd( int city, int car ){
	if( this->size == this->maxSize ){
		throw runtime_error( "Attempting to add to a full solution" );
	}
	this->cities.push_back( city );
	this->cars.push_back( car );
	this->size++;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
}

void Solution::removeIndex( int index ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Index for city/car pair removal in solution is not valid. " );
	}
	this->cities.erase( this->cities.begin() + index );
	this->cars.erase( this->cars.begin() + index );
	this->size--;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
}

void Solution::addCityAt( int index, int city ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Invalid index to add city.\n" );
	}
	this->cities.insert( this->cities.begin() + index, city );
	this->cars.insert( this->cars.begin() + index, cars[index] );
	this->size++;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
}

void Solution::addCityAndCarAt( int index, int city, int car ){
	if( index < 0 || index >= this->size ){
		throw runtime_error( "Invalid index to add car.\n" );
	}
	this->cities.insert( this->cities.begin() + index, city );
	this->cars.insert( this->cars.begin() + index, car );
	this->size++;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
}

void Solution::overwriteCityAt( int index, int city ){
	if( index < 0 || index > this->size ){
		throw runtime_error( "Invalid index to insert city.\n" );
	}
	this->cities[ index ] = city;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;
}

void Solution::overwriteCarAt( int index, int car ){
	if( index < 0 || index > this->size ){
		throw runtime_error( "Invalid index to insert car.\n" );
	}
	this->cars[ index ] = car;
	this->calculatedFitness = false;
	this->calculatedSatisfaction = false;

}

int Solution::getSize(){
	return this->size;
}

int Solution::getFitness(){
	if( !this->calculatedFitness ){
		calculeFitness();
		this->calculatedFitness = true;
	}
	return this->fitness;
}

int Solution::getSatisfaction(){
	if( !this->calculatedSatisfaction ){
		calculeSatisfaction();
		this->calculatedSatisfaction = true;
	}
	return this->satisfaction;
}

string Solution::toString(){
	string s = ">";
	string s2 = "*";
	for( int i = 0; i < size; i++ ){
		s += to_string( cities[i] ) + "\t";
		s2 += to_string( cars[i] ) + "\t";
	}
	return s + "\n" + s2;
}
