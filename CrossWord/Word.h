#ifndef __WORD__
#define __WORD__

#include "Include.h"

class Word {
private:
    string basic, word;
    Word *tail, *next;
    int x, y, index;
    int branch;
public:
    Word(string basic = "", string word = "", Word *tail = NULL, Word *next = NULL, int x = 0, int y = 0, int index = 0, int branch = -1);

    string getBasic();

    void setBasic(string basic);

    string getString();

    void setString(string s);

    Word *getNext();

    void setNext(Word *next);

    Word *getTail();

    void setTail(Word *node);

    void setX(int x);

    int getX();

    void setY(int y);

    int getY();

    void setIndex(int index);

    int getIndex();

    void setBranch(int branch);

    int getBranch();
};

#endif