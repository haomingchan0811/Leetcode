#include <iostream>
using namespace std;

// bit manipulation: recursive: 3.93%, ok
int getSum(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;		//终止条件：sum或者carry为0
	int sum = a ^ b;			//异或实现不进位的加法
	int carry = (a & b) << 1; 	//实现进位：与操作找到都是1的相加位，<< 1左移进位
	return getSum(sum, carry);
}

// bit manipulation: iterative: 3.93%, ok
   int getSum(int a, int b) {
	   if(a == 0) return b;
	   while(b != 0){
		   int carry = a & b;
		   a = a ^ b;
		   b = carry << 1;
	   }
	   return a;
   }


int main(){
	// default test case
	int c = 1;
	int d = 2;
	cout << getSum(c, d);
}



// follow up, how to get subtraction
// Iterative
int getSubtract(int a, int b) {
	while (b != 0) {
		int borrow = (~a) & b;
		a = a ^ b;
		b = borrow << 1;
	}
	return a;
}
