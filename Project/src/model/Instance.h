#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

#include "Car.h"

class Instance {
public:
	Instance( int numberCars, int numberCities );
	Instance( const Instance &e );
	virtual ~Instance();

	void  setCar( int index, Car c );
	Car getCar( int index );

	void setBonusSatisfaction( int index, int value );
	int getBonusSatisfaction( int index );
	double getMinimalSatisfaction();
	int getSatisfactionTotal();
	int getNumberCities();
	int getNumberCars();

	string toString();

private:
	int numbersCars;
	int numbersCities;

	const double MINIMAL_RATIO_SATISFACTION = 0.8;

	std::vector< Car > cars;
	std::vector< int > bonusSatisfaction;
	int satisfactionTotal;

};

#endif /* INSTANCE_H_ */
