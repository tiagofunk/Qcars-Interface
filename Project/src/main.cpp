#include <iostream>
#include <string>

#include "algorithm/Algorithm.h"
#include "utils/ArgumentReader.h"
#include "utils/InstanceReader.h"
#include "GlobalVariables.h"
#include "example/GeneratePopulationWithHeuristic.h"
#include "example/Counter.h"
#include "example/MultiOperatorsLocalSearch.h"
#include "example/EliteSelector.h"
#include "example/Memplas.h"
#include "example/EmptyMutation.h"

using namespace std;

int main(int argc, char *argv[]) {
	try{
		ArgumentReader arg( argc, argv );
		string file = arg.getValue( "--file" );
		int sizePopulation = stoi( arg.getValue( "--sizePopulation" ) );
		double sizePlasmideo = stod( arg.getValue( "--sizePlasmideo" ) );
		double cross = stod( arg.getValue( "--cross" ) );
		double ratio = stod( arg.getValue( "--elite" ) );
		int limitIterations = stoi( arg.getValue( "--limitIterations" ) );
//		string strategy = arg.getValue( "--strategy" );
//		string selectionStrategy = arg.getValue( "--selectionStrategy" );
//		string intermediaryStrategy = arg.getValue( "--intermediaryStrategy" );

		cout << file << endl;

		InstanceReader reader( file );
		Instance inst = reader.readInstance();
		GlobalVarables::instance = &inst;
		cout << "Leu a instância" << endl;

		PopulationGenerator * gen   = new GeneratePopulationWithHeuristic( sizePopulation );
		StoppingCriterion   * count = new Counter( limitIterations );
		PopulationOperator  * mul   = new MultiOperatorsLocalSearch();
		PopulationSelector  * elite = new EliteSelector( ratio, cross );
		PopulationCrossing  * mem   = new Memplas( sizePlasmideo );
		PopulationMutation  * mun   = new EmptyMutation();

		vector< PopulationOperator * > operators;
		operators.push_back( mul );

		Algorithm alg( gen, count, elite, mem, mun );
		alg.addBeforeLoop( operators );
		alg.addOnLoop( operators );
		alg.lets_go();

		cout << "foi de novo" << endl;
	}catch (exception &e){
		cerr << "This is a aplication error: "<< e.what() << endl;
		return 1;
	}

	return 0;
}
