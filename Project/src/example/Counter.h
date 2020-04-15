#include "../algorithm/StoppingCriterion.h"

#ifndef COUNTER_H_
#define COUNTER_H_

class Counter: public StoppingCriterion {
public:
	Counter( int stop );

	bool proceed();

private:
	int stop;
	int count;
};

#endif /* COUNTER_H_ */
