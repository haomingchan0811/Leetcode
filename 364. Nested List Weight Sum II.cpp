/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // hash map: O(N)time, O(depth)space, 16.58%, ok
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if(nestedList.empty()) return 0;
        unordered_map<int, int> levelSum;
        int totalDepth = 0, ret = 0;
        dfs(nestedList, 0, levelSum, totalDepth);
        cout << totalDepth << endl;
        for(auto n: levelSum)
            ret += (totalDepth- n.first) * n.second;
        return ret;
    }

    void dfs(vector<NestedInteger>& nestedList, int depth, unordered_map<int, int>& levelSum, int& totalDepth){
        // bug: totalDepth may be modified by less-layered elements later, should mantain max value
        totalDepth = max(totalDepth, depth + 1);
        for(auto n: nestedList){
            if(n.isInteger())
                levelSum[depth] += n.getInteger();
            else dfs(n.getList(), depth + 1, levelSum, totalDepth);
        }
    }

    // brilliant idea: add lower-level values multiple times
    // O(N)time, O(1)space, 16.58%, ok
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if(nestedList.empty()) return 0;
        int accum = 0, ret = 0;  // accum adds up all individual values level by level
        while(nestedList.size()){
            vector<NestedInteger> nextLevel;
            for(auto n: nestedList){
                if(n.isInteger())
                    accum += n.getInteger();
                else {
                    for(auto i: n.getList())
                        nextLevel.push_back(i);
                }
            }
            // brilliant: add lower-level values multiple times in this step
            ret += accum;
            nestedList = nextLevel;
        }
        return ret;
    }

};
