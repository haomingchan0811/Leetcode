#include <iostream>
using namespace std;

class Solution {
public:
    // 93.05%, ok
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int reg1 = area(A, B, C, D);  // area of the first regtangle
        int reg2 = area(E, F, G, H);
        int leftMax = max(A, E);    // left boundry of possible overlap
        int rightMin = min(C, G);
        int upMin = min(D, H);      // top boundry of possible overlap
        int downMax = max(B, F);
        // calculate the area of overlap
        int overlap = 0;
        if(leftMax < rightMin && upMin > downMax)  // bug: miss this procesure 
            overlap = area(leftMax, downMax, rightMin, upMin);
        return reg1 + reg2 - overlap;
    }

    int area(int a, int b, int c, int d){
        return (c - a) * (d - b);
    }
};

int main(){
    Solution sol;
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
}
