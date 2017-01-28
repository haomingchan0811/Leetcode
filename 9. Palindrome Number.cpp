class Solution {
public:
    // reverse int and compare: 66ms brute force: 54.55%, ok
    bool isPalindrome(int x) {
        if(!x) return true;
        if(x < 0 || x % 10 == 0) return false;
        int y = x;
        int reverse = 0;
        while(y){
            reverse = reverse * 10 + y % 10;
            y /= 10;
        }
        return x == reverse;
    }

    // compare only half of the string: 94.47%, ok
      bool isPalindrome(int x) {
          if(x < 0 || (x != 0 && x % 10 == 0)) return false; // bug?
          int sum = 0;
          while(x > sum){
              sum = sum * 10 + x % 10;
              x /= 10;
          }
          return x == sum || x == sum / 10;  // even comp || odd comp
      }
};
