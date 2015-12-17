#ifndef __WORD__
#define __WORD__

#include "Include.h"

class Word {
private:
	vector<string> word;
	vector<int> stringSizeIndex;
	int index;
public:
	void addWord(string s);
	void addIndex();
	vector<string> getWordVertor();
};

#endif