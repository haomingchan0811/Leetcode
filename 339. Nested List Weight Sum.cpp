/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // dfs: O(N)time & space, 7.16%, ok
    int depthSum(vector<NestedInteger>& nestedList) {
        if(nestedList.empty()) return 0;
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger> nestedList, int depth){
        int ret = 0;
        for(NestedInteger n: nestedList){
            if(n.isInteger())
                ret += n.getInteger() * depth;
            else
                ret += dfs(n.getList(), depth + 1);
        }
        return ret;
    }
};
