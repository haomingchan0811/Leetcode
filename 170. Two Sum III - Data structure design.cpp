// class TwoSum {
// public:
//     // TLE for last big data case
//     priority_queue<int> data;

//     /** Initialize your data structure here. */
//     TwoSum() {

//     }

//     /** Add the number to an internal data structure.. */
//     void add(int number) {
//         data.push(number);
//     }

//     /** Find if there exists any pair of numbers which sum is equal to the value. */
//     bool find(int value) {
//         if(data.empty()) return false;
//         unordered_map<int, bool> map;
//         priority_queue<int> data2 = data;
//         while(data2.size()){
//             int d = data2.top();
//             data2.pop();
//             if(map.empty() || !map.count(d))
//                 map[value - d] = true;
//             else return true;
//         }
//         return false;
//     }
// };

class TwoSum {
public:
    // hashmap: O(1), O(N)find & space, 74.05%, ok
    unordered_map<int, int> map;

    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        // bug: "= 1" will yield a == value but not a + b = value
        map[number] += 1;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto m: map){
            int comp = value - m.first;
            if((comp != m.first && map.count(comp)) || (comp == m.first && map[comp] > 1))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
