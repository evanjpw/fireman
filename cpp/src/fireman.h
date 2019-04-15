/*
 * fireman.h
 */

#ifndef FIREMAN_H_
#define FIREMAN_H_

#include <utility>
#include "TwoLetterBuckets.h"
#include "WordDepthPair.h"
#include "WordList.h"

class FireMan {
public:
	FireMan();
	virtual ~FireMan();
	std::pair<WordDepthPair, WordDepthPair> *solve();
private:
	WordList word_list;
	TwoLetterBuckets two_letter_buckets;
	int tryWord(const string &word, int depth = 0) const;
	WordDepthPair bestLengthPair;
	WordDepthPair bestDepthPair;
	std::pair<WordDepthPair, WordDepthPair> *solution;
};

#endif /* FIREMAN_H_ */
