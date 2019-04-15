/*
 * WordList.h
 *
 *  Created on: Apr 13, 2019
 *      Author: ejw
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_

#include <vector>
#include <string>

class WordList {
public:
	WordList();
	virtual ~WordList();
	const std::vector<std::string> *const words() const;
	std::vector<std::string> *reversed_words();
	std::vector<std::string> *reversed_words_longer_than_3();
private:
	std::vector<std::string> the_words;
	std::vector<std::string> *the_reversed_words_longer_than_three;
	std::vector<std::string> *the_reversed_words;
};

#endif /* WORDLIST_H_ */
