#include "FileWriter.h"

#include <fstream>
#include <exception>

FileWriter::FileWriter(string name) {
	this->name = name;
}

FileWriter::~FileWriter() {
}

void FileWriter::write(string text){
	ofstream file( this->name.c_str(), ios::app );

	if( !file ){
		throw runtime_error( "Error on open file: " + this->name );
	}
	file << text;
	file.close();
}
