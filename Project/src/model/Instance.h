#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

#include "Car.h"

class Instance {
public:
	Instance( int numberCars, int numberCities );
	virtual ~Instance();

	const double minimalSatisfaction = 0.8;

	Car getCar( int index );
	int getBonusSatisfaction( int index );
	int getSatisfactionTotal();

private:
	int numbersCars;
	int numbersCities;

	std::vector< Car > cars;
	std::vector< int > bonusSatisfaction;
	int satisfactionTotal;

};

#endif /* INSTANCE_H_ */
