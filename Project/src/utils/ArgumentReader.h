#ifndef ARGUMENTREADER_H_
#define ARGUMENTREADER_H_

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct Argument{
	string name;
	string value;
};

class ArgumentReader{
private:
	vector< Argument > arguments;

	void process( int size, string* args );

public:
	ArgumentReader( int argc, char* argv[] );
	string getValue( string name );
};

#endif /* ARGUMENTREADER_H_ */
