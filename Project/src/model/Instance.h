#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

#include "Car.h"

class Instance {
public:
	Instance( int numberCars, int numberCities );
	virtual ~Instance();

	/**
	 * Value that represents a minimum satisfaction proportion value.
	 */
	const double minimalSatisfaction = 0.8;

	/**
	 * Inserts car on index in list of cars.
	 */
	void  setCar( int index, Car c );

	/**
	 * Returns car on index in list of cars.
	 */
	Car getCar( int index );

	void setBonusSatisfaction( int index, int value );
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
