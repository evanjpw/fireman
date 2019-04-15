/*
 * TwoLetterBuckets.h
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#ifndef TWOLETTERBUCKETS_H_
#define TWOLETTERBUCKETS_H_

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<std::string> Bucket;

class TwoLetterBuckets {
public:
	TwoLetterBuckets();
	virtual ~TwoLetterBuckets();
	void sort_buckets();
	void add(const std::string &word);
	Bucket *getByWord(const std::string &word) const;
private:
	std::unordered_map<std::string, *Bucket> buckets;
};

#endif /* TWOLETTERBUCKETS_H_ */
