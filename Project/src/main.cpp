#include <iostream>
#include <string>

#include "algorithm/Algorithm.h"
#include "utils/ArgumentReader.h"
#include "utils/InstanceReader.h"
#include "GlobalVariables.h"

using namespace std;

int main(int argc, char *argv[]) {
	try{
		ArgumentReader arg( argc, argv );
		string file = arg.getValue( "--file" );
//		int sizePopulation = stoi( arg.getValue( "--sizePopulation" ) );
//		double sizePlasmideo = stod( arg.getValue( "--sizePlasmideo" ) );
//		double cross = stod( arg.getValue( "--cross" ) );
//		double elite = stod( arg.getValue( "--elite" ) );
//		int limitIterations = stoi( arg.getValue( "--limitIterations" ) );
//		string strategy = arg.getValue( "--strategy" );
//		string selectionStrategy = arg.getValue( "--selectionStrategy" );
//		string intermediaryStrategy = arg.getValue( "--intermediaryStrategy" );

		cout << file << endl;
		InstanceReader reader( file );
		Instance inst = reader.readInstance();
		GlobalVarables::instance = &inst;
		cout << "foi" << endl;
		cout << GlobalVarables::instance->getNumberCars()<< endl;

	}catch (exception &e){
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}
