#ifndef VALIDATE_H_
#define VALIDATE_H_

#include "../model/Solution.h"

class Validate {
public:
	Validate();
	virtual ~Validate();

	bool isValid( Solution mySolution );
	void isOk( Solution mySolution ) throw (runtime_error);
	void checkPopulation( vector< Solution > population );

private:
	void verifyQuota( Solution sol );
	void checkStartAndEnd( Solution sol, int finalPosition );
	void checkCitiesAndCars( Solution sol, int finalPosition );
	void checkRepetition( Solution sol, int finalPosition );

};

#endif /* VALIDATE_H_ */
