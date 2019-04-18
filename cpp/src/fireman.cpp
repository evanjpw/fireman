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
	const vector<string> *words = word_list.reversed_words();
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
		//g()
		if (word->length() < (bestDepthPair.depth * 3) && word->length() < bestLengthPair.length()) {
//            continue;
            solution = new std::pair<WordDepthPair, WordDepthPair>(bestDepthPair, bestLengthPair);
            return solution;
		}
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
        //sub_word_iterator;.() //sub_word_length &&
        for(const auto& sub_word : *bucket) {
            const int sub_word_length = sub_word.length();
            if (sub_word_length <= word_length && sub_word_length >= 3 &&
                !strncmp(word.c_str(), sub_word.c_str(), sub_word_length)
                //!word.compare(0, sub_word_length, sub_word)
                ) {
                const string word_fragment(word.substr(sub_word_length));
                const int ndepth = this->tryWord(word_fragment, depth + 1);
                if (ndepth > best_depth)
                    best_depth = ndepth;
            }
        }
    }

    return best_depth;
}
//            int b_word_length = sub_word.length();
//                      [word, &best_depth, this, depth, word_length](string &sub_word) ->begin();  bucket->end() != sub_word_iterator; ++sub_word_iteratorsub_word_iterator
//        string  = sub_word_iteratorord_iterator->
//        Bucket filtered_bucket(bucket->size());
//        std::copy_if(bucket->begin(),
//                     bucket->end(),
//                     std::back_inserter(filtered_bucket),
//                     [](string b_word) {
//                     });filtered_filtered_
// else {return false;};
