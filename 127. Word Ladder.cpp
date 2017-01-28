#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> neighbour;
        neighbour.push(beginWord);
        int length = 1;     // initail ladder length
        while(!neighbour.empty()){
            int size = neighbour.size();
            length++;
            while(size--){
                string cur = neighbour.front();
                cout << cur;
                neighbour.pop();
                if(endWord == cur) return length;
                cout << "yo";
                addNeighbour(cur, wordList, neighbour);
                cout << "hey";
            }
        }
        return 0;
    }

    void addNeighbour(string word, unordered_set<string>& wordList, queue<string>& neighbour){
        for(int i = 0; i < word.size(); i++){
            for(int j = 0; j < 26; j++){
                string trans = word;
                trans[i] = 'a' + j;
                cout << trans << endl;
                if(wordList.find(trans) != wordList.end()){
                    cout << trans << endl;
                    neighbour.push(trans);
                    wordList.erase(trans);
                }
            }
        }
    }
};

int main(){
    Solution sol;
    string w[3] = {"a", "b", "c"};
    unordered_set<string> wl(w, w + 3);
    cout << sol.ladderLength("a", "c", wl);
}
