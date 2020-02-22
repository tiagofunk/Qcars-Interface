#include "Car.h"

Car::Car(){
	this->dimension = dimension;
}
Car::Car(int dimension ) {
	this->dimension = dimension;
}

Car::~Car() {

}

int Car::getEdgeWeigth( int x, int y ){
	return this->edgeWeigth[ x ][ y ];
}

int Car::getReturnRate( int x, int y ){
	return this->returnRate[ x ][ y ];
}
