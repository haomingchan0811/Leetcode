#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
    pair<int, int> split(string x){
        string first, second;
        int xf, xs;
        string temp = "";
        bool exist = false;  // bug: whether '.' exists or not
        for(auto i: x){
            if(i != '.')
                temp += i;
            else{
                exist = true;
                first = temp;
                temp = "";
            }
        }
        if(exist) second = temp;
        else{
            first = temp;
            second = "0";
        }
        stringstream stream;
        stream << first;
        stream >> xf;
        stream.clear();     // bug: should clean the stringsteam before reuse
        stream << second;
        stream >> xs;
        // cout << xf << " " << xs << endl;
        pair<int, int> ans;
        ans.first = xf;
        ans.second = xs;
        return ans;
    }

    // using sstream to convert string into int
    // bug: 1.10 > 1.1 which can't be detected by direct stringstream
    int compareVersion(string version1, string version2) {
        // double v1, v2;      // bug: should not be int
        int v1_f, v1_s, v2_f, v2_s;
        pair<int, int> v1_p = split(version1);
        pair<int, int> v2_p = split(version2);
        v1_f = v1_p.first;
        v1_s = v1_p.second;
        v2_f = v2_p.first;
        v2_s = v2_p.second;
        if(v1_f == v2_f){
            if(v1_s == v2_s) return 0;
            else return v1_s > v2_s ? 1 : -1;
        }
        else
            return v1_f > v2_f ? 1 : -1;
    }
};

int main(){
    string v1 = "0";
    string v2 = "1";
    Solution sol;
    cout << sol.compareVersion(v1, v2) << endl;
}
