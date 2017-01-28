class Solution {
public:
    // customized sort and insert: O(n2), 46.33%, ok
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret;
        if(people.empty()) return people;
        sort(people.begin(), people.end(), mySort);
        for(auto p: people)
            ret.insert(ret.begin() + p.second, p);
        return ret;
    }

    static bool mySort(pair<int, int> a, pair<int, int> b){
        if(a.first > b.first)
            return true;
        else if(a.first == b.first && a.second < b.second)
            return true;
        return false;
    }
};
