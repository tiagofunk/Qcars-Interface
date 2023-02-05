#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "model/Solution.h"
#include "algorithm/Algorithm.h"
#include "utils/ArgumentReader.h"
#include "utils/InstanceReader.h"
#include "utils/FileWriter.h"
#include "GlobalVariables.h"
#include "example/GeneratePopulationWithHeuristic.h"
#include "example/Counter.h"
#include "example/MultiOperatorsLocalSearch.h"
#include "example/EliteSelector.h"
#include "example/Memplas.h"
#include "example/EmptyMutation.h"
#include "example/BinaryTournament.h"
#include "example/PathRelinking.h"
#include "example/SelectBetter.h"

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
		string strategy = arg.getValue( "--strategy" );
		string selectionStrategy = arg.getValue( "--selectionStrategy" );
		string intermediaryStrategy = arg.getValue( "--intermediaryStrategy" );

		srand( time( 0 ) );

		InstanceReader reader( file );
		Instance inst = reader.readInstance();
		GlobalVarables::instance = &inst;

		PopulationGenerator * gen    = new GeneratePopulationWithHeuristic( sizePopulation );
		StoppingCriterion   * count  = new Counter( limitIterations );
		PopulationOperator  * mul    = new MultiOperatorsLocalSearch();
		PopulationSelector  * elite  = new EliteSelector( ratio, cross );
		PopulationCrossing  * mem    = new Memplas( sizePlasmideo );
		PopulationMutation  * mun    = new EmptyMutation();
		PopulationUpdater   * upd    = new BinaryTournament();
		PopulationOperator  * path   = new PathRelinking( selectionStrategy, intermediaryStrategy );
		PopulationSelector  * better = new SelectBetter();

		vector< PopulationOperator * > operators;
		operators.push_back( mul );

		Algorithm alg( gen, count, elite, mem, mun, upd, better );

		alg.addBeforeLoop( operators );

//		operators.push_back( path );
		alg.addOnLoop( operators );

		Solution s = alg.lets_go();
		cout << file << ";" << s.getFitness() << endl;

	}catch (exception &e){
		cerr << "This is a aplication error: "<< e.what() << endl;
		return 1;
	}

	return 0;
}
