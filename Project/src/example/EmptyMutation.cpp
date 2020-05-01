#include "EmptyMutation.h"

EmptyMutation::EmptyMutation() {
}

EmptyMutation::~EmptyMutation() {
}

vector< Solution > EmptyMutation::apply( vector< Solution > population ){
	return population;
}
