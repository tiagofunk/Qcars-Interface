#ifndef CAR_H_
#define CAR_H_

#include <vector>

class Car {
public:
	Car( int dimension );
	virtual ~Car();

	void setEgdeWeigth( int x, int y, int value );
	void setReturnRate( int x, int y, int value );
	int getEdgeWeigth( int x, int y );
	int getReturnRate( int x, int y );

private:
	int dimension;
	std::vector< std::vector< int > > edgeWeigth;
	std::vector< std::vector< int > > returnRate;

};

#endif /* CAR_H_ */
