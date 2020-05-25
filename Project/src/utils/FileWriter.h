#ifndef FILEWRITER_H_
#define FILEWRITER_H_

#include <string>

using namespace std;

class FileWriter {
public:
	FileWriter(string name);
	virtual ~FileWriter();

	void write(string text);
private:
	string name;
};

#endif /* FILEWRITER_H_ */
