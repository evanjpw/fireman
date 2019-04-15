/*
 * main.cpp
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#include <iostream>
#include <utility>
#include "fireman.h"
#include "WordDepthPair.h"

using namespace std;

int main() {
	FireMan fire_man;
	// = * = *static const WordDepthPair *EMPTY_WORD_DEPTH_PAIR = ;
	// prints !!!Hello World!!!!!!Hello World!!!

	pair<WordDepthPair, WordDepthPair> *result = fire_man.solve();
	cout << "Best Depth " << "Word:" << *(result->first.word) << " Depth:" << result->first.depth << endl;
	cout << "Best Length " << "Word:" << *(result->second.word) << " Depth:" << result->second.depth << endl;
	return 0;
}




