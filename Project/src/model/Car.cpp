#include "Car.h"

Car::Car(int dimension ) {
	this->dimension = dimension;
	this->edgeWeigth.resize( dimension );
	this->returnRate.resize( dimension );
	for( int i = 0; i < dimension; i++ ){
		this->edgeWeigth[ i ].resize( dimension );
		this->returnRate[ i ].resize( dimension );
	}
}

Car::~Car() {
}

void Car::setEgdeWeigth( int x, int y, int value ){
	this->edgeWeigth[ x ][ y ] = value;
}

void Car::setReturnRate( int x, int y, int value ){
	this->returnRate[ x ][ y ] = value;
}

int Car::getEdgeWeigth( int x, int y ){
	return this->edgeWeigth[ x ][ y ];
}

int Car::getReturnRate( int x, int y ){
	return this->returnRate[ x ][ y ];
}
