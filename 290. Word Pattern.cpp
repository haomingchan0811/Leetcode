#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/* Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.*/

bool wordPattern(string pattern, string str) {
		unordered_map<string, char> hash_map;   // store the word-letter pair
		unordered_map<char, int> hash_pattern;	// record whether a letter has shown before
		int count = 0;          // iterator of the pattern string
		while(str.size()){
			string word = "";
			int word_length = 0;        // the length of the current word
			for(int j = 0; j < str.size() && str[j] != ' '; j ++){                
				word += str[j];         // bug: can't use "word[j] = str[j]""
				word_length ++;
			}
			str.erase(0, word_length + 1);  // cut the current word and the consecutive single space
		    char letter = pattern[count ++];
			if(!hash_map.count(word)){
		    	if(!hash_pattern.count(letter)){
			    	hash_map[word] = letter;
				    hash_pattern[letter] = 1;	
			    }
			    else 
				    return false;
		    }
		    else{
			    if(hash_map[word] == letter)
					continue;
				else
					return false;
			}
		}
		// bug: must check whether the length of the pattern equals to the number of words.
		if(count == pattern.size())    
			return true;
		else
			return false;
	}
	
// improve using istringstream
bool wordPattern(string pattern, string str) {
	unordered_map<string, char> hash_map;   // store the word-letter pair
	unordered_map<char, int> hash_pattern;	// record whether a letter has shown before

	/****************************************/
	/* split str into words by single space */
	/****************************************/
	istringstream cut_string(str);          
	vector<string> word;
	string temp;
	while(cut_string >> temp)
		word.push_back(temp);
	
	// bug: must check whether the length of the pattern equals to the number of words.
	if(word.size() != pattern.size())    
		return false;

	for(int i = 0; i < word.size(); i ++){
	    char letter = pattern[i];
		if(!hash_map.count(word[i]) && !hash_pattern.count(letter)){
		    hash_map[word[i]] = letter;
		    hash_pattern[letter] = 1;	
		}
	    else{
		    if(hash_map[word[i]] != letter)
				return false;
		}
	}
	return true;
}

int main(){
	// default test case
	string x = "abba";  			// bug test case: "jqwery"
	string y = "dog cat cat dog"; 	// "jqwery"
	cout << wordPattern(x, y);
}
