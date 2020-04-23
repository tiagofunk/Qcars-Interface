#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution {
public:
	Solution();
	Solution( int maxSizeSolution );
	~Solution();

	/**
	 * Returns the size of the solutions.
	 */
	int getSize();

	/**
	 * Returns the fitness of the solution.
	 */
	int getFitness();

	/**
	 * Returns the level satisfaction of the solution.
	 */
	int getSatisfaction();

	/**
	 * Add city and car on end of the solution.
	 */
	void addEnd( int city, int car );

	/**
	 * Removes city and car on index of the solution.
	 */
	void removeIndex( int index );

	/**
	 * Add city to the solution index. The car is copied from the previous position.
	 */
	void addCityAt( int index, int city );

	/**
	 * Add city and car on index of the solution.
	 */
	void addCityAndCarAt( int index, int city, int car );

	/**
	 * Overwrite city on index.
	 */
	void overwriteCityAt( int index, int city );

	/**
	 * Overwrite car on index.
	 */
	void overwriteCarAt( int index, int car );

	int getCityAt( int position );

	int getCarAt( int position );

	int getQtyCity();

	int getQtyCar();

	/**
	 * Create text that represents the solution.
	 */
	string toString();

	bool operator>(Solution &sol);
	bool operator<(Solution &sol);

private:
	bool calculatedFitness;
	bool calculatedSatisfaction;

	int size;
	int maxSize;
	int fitness;
	int satisfaction;

	vector< int > cities;
	vector< int > cars;

	void calculeFitness();
	void calculeSatisfaction();

};

#endif /* SOLUTION_H_ */
