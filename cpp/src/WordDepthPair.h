/*
 * WordDepthPair.h
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#ifndef WORDDEPTHPAIR_H_
#define WORDDEPTHPAIR_H_

#include <string>

using namespace std;

class WordDepthPair {
public:
	WordDepthPair(string& word, int depth);
	WordDepthPair();
	virtual ~WordDepthPair();
	int size() const { return word ? word->size() : 0; }
	int length() const { return word ? word->length() : 0; }
	int compare(const WordDepthPair& other) const;
	string *word;
	int depth;
};

#endif /* WORDDEPTHPAIR_H_ */
