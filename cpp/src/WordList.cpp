/*
 * WordList.cpp
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#include <iostream>
#include <fstream>
#include "WordList.h"

using namespace std;

bool compareWordsByLengthDescending(const string &first_word, const string &second_word) {
    return first_word.length() > second_word.length();
}


static const string WORD_LIST_FILE_PATH = "../words.txt";

WordList::WordList() {
	ifstream word_list_stream(WORD_LIST_FILE_PATH);
	if (word_list_stream) {
		for(string line; getline(word_list_stream, line);)
			this->the_words.push_back(line);
	} else {
	    cerr << "Could not find file: " << WORD_LIST_FILE_PATH << endl;
		// print some useful information about the_words not being
		// Initialized because the file stream == NULL;
	}
	the_reversed_words_longer_than_three = nullptr;
	the_reversed_words = nullptr;
}

WordList::~WordList() {

		delete the_reversed_words;

		delete the_reversed_words_longer_than_three;
}

const vector<string> *const WordList::words() const {
	return &the_words;
}

vector<string> *WordList::reversed_words_longer_than_3() {
	if (!the_reversed_words_longer_than_three) {
		vector<string> *rwords = reversed_words();
		the_reversed_words_longer_than_three = new vector<string>();
		for (auto & word : *rwords) {
				if (word.length() >= 3) {
				the_reversed_words_longer_than_three->push_back(word);
			}
		}
	}
	return the_reversed_words_longer_than_three;
}

vector<string> *WordList::reversed_words() {
    if (!the_reversed_words) {
        the_reversed_words = new vector<string>(the_words);
        std::sort (the_reversed_words->begin(), the_reversed_words->end(), compareWordsByLengthDescending);
    }
    return the_reversed_words;
}
//.r.r
