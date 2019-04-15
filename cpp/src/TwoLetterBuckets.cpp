/*
 * TwoLetterBuckets.cpp
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#include "TwoLetterBuckets.h"

using namespace std;

bool compareWordsByLength(const string &first_word, const string &second_word) {
	return first_word.length() < second_word.length();
}

TwoLetterBuckets::TwoLetterBuckets() = default;

TwoLetterBuckets::~TwoLetterBuckets() = default;

void TwoLetterBuckets::add(const string &word) {
    shared_ptr<string> key = wordToKey(word);
    Bucket * bucket = nullptr;
    if (!buckets.count(*key)) {
        bucket = new Bucket;
        buckets[*key] = bucket;
    } else {
        bucket = buckets[*key];
    }
    bucket->push_back(word);
}

void TwoLetterBuckets::sort_buckets() {
    for (auto & buckets_iterator : buckets) {
        Bucket *bucket = buckets_iterator.second;
        std::sort (bucket->begin(), bucket->end(), compareWordsByLength);//
    }
}

Bucket* TwoLetterBuckets::getByWord(const std::string &word) const {
    shared_ptr<string> key = wordToKey(word);
    return buckets.count(*key) ? buckets.at(*key) : nullptr;
}

shared_ptr<string> TwoLetterBuckets::wordToKey(const string &word) const {
    return shared_ptr<string>(new string(word, 0, 2));
}