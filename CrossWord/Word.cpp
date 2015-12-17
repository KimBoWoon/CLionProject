#include "Word.h"

void Word::addWord(string s) {
	index++;
	word.push_back(s);
}

void Word::addIndex() {
	stringSizeIndex.push_back(index);
}

vector<string> Word::getWordVertor() {
	return word;
}