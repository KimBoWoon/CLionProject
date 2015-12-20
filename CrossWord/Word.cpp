#include "Word.h"

Word::Word(string basic, string word, Word *tail, Word *next, int x, int y, int index, int branch) {
    this->basic = basic;
    this->word = word;
    this->tail = tail;
    this->next = next;
    this->x = x;
    this->y = y;
    this->index = index;
    this->branch = branch;
}

string Word::getBasic() {
    return basic;
}

void Word::setBasic(string basic) {
    this->basic = basic;
}

string Word::getString() {
    return word;
}

void Word::setString(string s) {
    this->word = s;
}

Word *Word::getNext() {
    return next;
}

void Word::setNext(Word *next) {
    this->next = next;
}

Word *Word::getTail() {
    return tail;
}

void Word::setTail(Word *node) {
    this->tail = node;
}

void Word::setX(int x) {
    this->x = x;
}

int Word::getX() {
    return x;
}

void Word::setY(int y) {
    this->y = y;
}

int Word::getY() {
    return y;
}

void Word::setIndex(int index) {
    this->index = index;
}

int Word::getIndex() {
    return index;
}

void Word::setBranch(int branch) {
    this->branch = branch;
}

int Word::getBranch() {
    return branch;
}