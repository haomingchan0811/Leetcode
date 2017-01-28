#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:

    // The sieve of Eratosthenes can be expressed in pseudocode

    // Input: an integer n > 1
    //
    // Let A be an array of Boolean values, indexed by integers 2 to n,
    // initially all set to true.
    //
    // for i = 2, 3, 4, ..., not exceeding √n:
    //   if A[i] is true:
    //     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
    //       A[j] := false
    // Output: all i such that A[i] is true.

    /*
    // Direct Implement: 316ms
    int countPrimes(int n){
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i * i < n; i ++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }*/

    // Implement that ignores even numbers in every step: 119ms
    int countPrimes(int n){
        if(n <= 2) return 0;  //bug: count initialize to 1 applys to n >= 2
        vector<bool> isPrime(n, true);
        isPrime[2] = 1;
        for(int i = 3; i < sqrt(n); i += 2){ // ignore even numbers
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i * 2)
                    isPrime[j] = false;
            }
        }
        int count = 1; // first prime: 2
        // still ignore even numbers cause we dont have them iterated
        for(int i = 3; i < n; i += 2)
            if(isPrime[i])
                count ++;
        return count;
    }

    /*
    // Brute force: 896ms or TLE
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2) return 0;
        int count = 1;  // first prime 2
        for(int i = 3; i < n; i += 2)
            if(isPrime(i)) count ++;
        return count;
    }

    bool isPrime(int n){
        for(int i = 2; i * i <= n; i ++){
            if(n % i == 0)
                return false;
        }
        return true;
    }*/
};

int main(){
    int test = 5;
    Solution sol;
    cout << sol.countPrimes(test);
}
