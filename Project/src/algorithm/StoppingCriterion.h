
#ifndef STOPPINGCRITERION_H_
#define STOPPINGCRITERION_H_

class StoppingCriterion{
public:
	virtual ~StoppingCriterion(){
	}

	virtual bool proceed() = 0;
};



#endif /* STOPPINGCRITERION_H_ */
