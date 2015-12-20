#ifndef __INCLUDE__
#define __INCLUDE__

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;

#define MAX_SIZE 50
#define ACROSS 0
#define DOWN 1

bool sizeComp(const string x, const string y);

void inputBoard(char board[][MAX_SIZE], int row, int col);

string selectWord(string str, int x, int y, int branch, int index = -1);

void backtracking();

void acrossWord(int across, int col);

void downWord(int down, int row);

void printBoard(char board[][MAX_SIZE], int row, int col);

#endif