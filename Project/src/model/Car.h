#ifndef CAR_H_
#define CAR_H_

#include <vector>

class Car {
public:
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

private:
	int dimension;

	std::vector< std::vector< int > > edgeWeigth;
	std::vector< std::vector< int > > returnRate;

};

#endif /* CAR_H_ */
