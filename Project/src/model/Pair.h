#ifndef PAIR_H_
#define PAIR_H_

class Pair{
public:
	Pair( int key, int value ){
		this->key = key;
		this->value = value;
	}

	void setKey( int key ){
		this->key = key;
	}
	void setValue( int value ){
		this->value = value;
	}
	void plusValue(){
		this->value++;
	}
	void minusValue(){
		this->value--;
	}
	int getKey(){
		return this->key;
	}
	int getValue(){
		return this->value;
	}

	bool operator>(Pair &pair){
		return this->value > pair.getValue();
	}

	bool operator<(Pair &pair){
		return this->value < pair.getValue();
	}

private:
	int key;
	int value;
};



#endif /* PAIR_H_ */
