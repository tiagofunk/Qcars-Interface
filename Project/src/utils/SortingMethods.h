#ifndef SORTINGMETHODS_H_
#define SORTINGMETHODS_H_

#include <vector>

using namespace std;

template <typename T>
class SortingMethods {
public:
	SortingMethods(){}
	virtual ~SortingMethods(){}


	vector< T > sort( vector< T > population );

private:
	vector< T > quickSort( vector< T > population, int begin, int end );

};

// https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
template <typename T>
vector< T > SortingMethods<T>::sort( vector< T > population ){
	return this->quickSort( population, 0, (int) population.size() );
}

template <typename T>
vector< T > SortingMethods<T>::quickSort( vector< T > population, int begin, int end ){
	int i, j;
	i = begin;
	j = end-1;
	T pivo = population[ (begin + end) / 2 ];
	while(i <= j){
		while(population[i] < pivo && i < end){
			i++;
		}
		while(population[j] > pivo && j > begin){
			j--;
		}
		if(i <= j){
			T aux = population[i];
			population[i] = population[j];
			population[j] = aux;
			i++;
			j--;
		}
	}
	if(j > begin){
		population = this->quickSort(population, begin, j+1);
	}
	if(i < end){
		population = this->quickSort(population, i, end);
	}
	return population;
}

#endif /* SORTINGMETHODS_H_ */
