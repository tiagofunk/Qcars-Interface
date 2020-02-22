#ifndef CAR_H_
#define CAR_H_

#include <vector>

class Car {
public:
	Car();
	Car( int dimension );
	virtual ~Car();

	int getEdgeWeigth( int x, int y );
	int getReturnRate( int x, int y );

private:
	int dimension;
	std::vector< std::vector< int > > edgeWeigth;
	std::vector< std::vector< int > > returnRate;

};

#endif /* CAR_H_ */
