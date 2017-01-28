class Solution {
public:
	// unorderd map solution
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> letters;   // to store the available letters
		for(int i = 0; i < magazine.size(); i ++)       // record the letters and their corrsponding quantity
			letters[magazine[i]] ++;
		for(int i = 0; i < ransomNote.size(); i ++)      // check the ransom note
			if(-- letters[ransomNote[i]] < 0)
				return false;
		return true;
	}

    // use vector as hashtable: O(m+n), 61.01%, ok
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letter(26, 0);
        for(auto c: magazine) letter[c - 'a']++;
        for(auto c: ransomNote){
            if(--letter[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
