#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

#include "Car.h"

class Instance {
public:
	Instance( int numberCars, int numberCities );
	Instance( const Instance &e);
	virtual ~Instance();

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
	double getMinimalSatisfaction();
	int getSatisfactionTotal();
	int getNumberCities();
	int getNumberCars();

private:
	int numbersCars;
	int numbersCities;

	/**
	 * Value that represents a minimum satisfaction proportion value.
	 */
	const double minimalRatioSatisfaction = 0.8;

	std::vector< Car > cars;
	std::vector< int > bonusSatisfaction;
	int satisfactionTotal;

};

#endif /* INSTANCE_H_ */
