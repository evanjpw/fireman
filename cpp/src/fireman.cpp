//============================================================================
// Name        : fireman.cpp
// Author      : Evan Williams
// Version     :
// Copyright   : Your copyright notice
// Description : The ITA fireman puzzle
//============================================================================

#include <algorithm>
#include <memory>
#include "fireman.h"

using namespace std;


FireMan::FireMan() {
	vector<string> *words = word_list.words();
	for (int i = 0 ; i < words->size(); i++)
		two_letter_buckets.add((*words)[i]);
	two_letter_buckets.sort_buckets();
	solution = NULL;
}

FireMan::~FireMan() {
	if (solution)
		delete solution;
}

pair<WordDepthPair, WordDepthPair> *FireMan::solve() {

	vector<string> *words = word_list.reversed_words_longer_than_3();
	for (int i = 0; i < words->size(); i++) {
		string *word = words[i];
		int depth = tryWord(*word);
		if (depth > bestDepthPair.depth) {
			bestDepthPair.word = word;
			bestDepthPair.depth = depth;
		}
		if (word->length() > bestLengthPair.length()) {
			bestLengthPair.word = word;
			bestLengthPair.depth = depth;
		}
	}
	solution = new std::pair(bestDepthPair, bestLengthPair);
	return solution;
}

int FireMan::tryWord(const string &word, int depth = 0)	const {
	if (!word || word.length() == 0)
		return depth;
	int best_depth = 0;
	const Bucket *bucket = two_letter_buckets.getByWord(word);
	if (bucket) {
		Bucket filtered_bucket(bucket->size());
		std::copy_if(bucket->begin(),
				bucket->end(),
				std::back_inserter(filtered_bucket),
				[](string *b_word) {
			int b_word_length = b_word->length();
			return b_word_length <= word.length() && b_word_length >= 3;
		});
		std::for_each(filtered_bucket.begin(),
				filtered_bucket.end(),
				[](string *sub_word) {
			if (!word.compare(0, sub_word->size(), *sub_word)) {
				int ndepth = tryWord(word.substr(sub_word->size()));
				if (ndepth > best_depth)
					best_depth = ndepth;
			}
		});
	}
	return best_depth;
}
