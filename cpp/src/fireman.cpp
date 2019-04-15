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
	const vector<string> *words = word_list.words();
	for (const auto & word : *words)
		two_letter_buckets.add(word);
	two_letter_buckets.sort_buckets();
	solution = nullptr;
}

FireMan::~FireMan() {

		delete solution;
}

pair<WordDepthPair, WordDepthPair> *FireMan::solve() {

	vector<string> *words = word_list.reversed_words_longer_than_3();
	for (auto & i : *words) {
		string *word = &i;
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
	solution = new std::pair<WordDepthPair, WordDepthPair>(bestDepthPair, bestLengthPair);
	return solution;
}

int FireMan::tryWord(const string &word, int depth)	const {
    const int word_length = word.length();
    if (0 == word_length)
        return depth;
    int best_depth = 0;
    Bucket *bucket = two_letter_buckets.getByWord(word);
    if (bucket) {
        Bucket filtered_bucket(bucket->size());
        std::copy_if(bucket->begin(),
                     bucket->end(),
                     std::back_inserter(filtered_bucket),
                     [word_length](string b_word) {
                         int b_word_length = b_word.length();
                         if (b_word_length <= word_length) {
                             return b_word_length >= 3;
                         } else {
                             return false;
                         }
                     });
        std::for_each(filtered_bucket.begin(),
                      filtered_bucket.end(),
                      [word, &best_depth, this, depth](string &sub_word) {
                        const int sub_word_length = sub_word.length();
                          if (sub_word_length && !word.compare(0, sub_word_length, sub_word)) {
                              int ndepth = this->tryWord(word.substr(sub_word.length()), depth + 1);
                              if (ndepth > best_depth)
                                  best_depth = ndepth;
                          }
                      });
    }
    return best_depth;
}
//
