#ifndef PAIR_H_
#define PAIR_H_

class Pair{
public:
	Pair( int key, int value ){
		this->key = key;
		this->value = value;
	}

	int getKey(){
		return this->key;
	}
	int getValue(){
		return this->value;
	}

private:
	int key;
	int value;
};



#endif /* PAIR_H_ */
