#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <stdexcept>
#include <vector>

#include "Instance.h"
#include "../GLOBAL.h"

using namespace std;

class Solution {
public:
	Solution();
	Solution( int maxSizeSolution );
	~Solution();

	int getSize();
	int getFitness();
	int getSatisfaction();

	string toString();

private:
	bool calculatedFitness;

	int size;
	int maxSize;
	int fitness;
	int satisfaction;

	vector< int > cities;
	vector< int > cars;

	void calculeFitness();
	void calculeSatisfaction();

	void addEnd( int city, int car );
	void removeIndex( int index );
	void addCityAt( int index, int city );
	void addCityAndCarAt( int index, int city, int car );
	void insertCityAt( int index, int city );
	void insertCarAt( int index, int car );

};

#endif /* SOLUTION_H_ */
