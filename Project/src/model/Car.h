#ifndef CAR_H_
#define CAR_H_

#include <vector>
#include <iostream>

using namespace std;

class Car {
public:
	Car(){this->dimension=0;};
	Car( int dimension );
	virtual ~Car();

	/**
	 * Inserts edge weigth on position (x,y).
	 */
	void setEgdeWeigth( int x, int y, int value );

	/**
	 * Inserts return rate on position (x,y).
	 */
	void setReturnRate( int x, int y, int value );

	/**
	 * Returns edge weigth on position (x,y).
	 */
	int getEdgeWeigth( int x, int y );

	/**
	 * Returns return rate on position (x,y).
	 */
	int getReturnRate( int x, int y );

	void toString();

private:
	int dimension;

	std::vector< std::vector< int > > edgeWeigth;
	std::vector< std::vector< int > > returnRate;

};

#endif /* CAR_H_ */
