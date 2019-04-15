/*
 * WordDepthPair.cpp
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#include "WordDepthPair.h"

WordDepthPair::WordDepthPair(string& word, const int depth) {
	this->word = &word;
	this->depth = depth;
}

WordDepthPair::WordDepthPair() {
	this->word = nullptr;
	this->depth = 0;
}

WordDepthPair::~WordDepthPair() = default;

int WordDepthPair::compare(const WordDepthPair& other) const {
	if (other.depth > depth)
		return -1;
	else if (other.depth < depth)
		return 1;
	else
		return 0;
}
