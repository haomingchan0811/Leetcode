// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    // recursive: 7.61%, ok
    int guessNumber(int n) {
        int head = 1, tail = n;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(guess(mid) == 1) head = mid + 1;
            else if(guess(mid) == -1) tail = mid - 1;
            else return mid;
        }
        return head;
    }
};
