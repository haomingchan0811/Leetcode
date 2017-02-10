#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <stack>
#include <vector>
using namespace std;

int main (){
//   std::priority_queue<int> mypq;
//
//   mypq.push(30);
//   mypq.push(100);
//   mypq.push(25);
//   mypq.push(40);
//
//   for(int i = 0; i < mypq.size(); i ++){
//       cout << mypq.top() << endl;
//       mypq.pop();
// }
//   while (!mypq.empty())
//   {
//      std::cout << ' ' << mypq.top();
//      mypq.pop();
//   }
//   std::cout << '\n';
//
//   return 0;
    stack<string> s;
    s.push("hello");
    // cout << s.top();
    s.top() += "world";
    cout << s.top();
}
