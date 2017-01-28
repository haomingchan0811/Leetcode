#include <iostream>
using namespace std;

void insertSort(int test[], int len){
    for(int i = 1; i < len; i ++){
        for(int j = i; j > 0; j --){
            if(test[j - 1] > test[j]){
                int temp = test[j - 1];
                test[j - 1] = test[j];
                test[j] = temp;
            }
            for(int i = 0; i < len; i ++)
                cout << test[i] << " ";
            cout << endl;
        }
    }
}

void bubbleSort_normal(int test[], int len){
    for(int i = 0; i < len; i ++){
        for(int j = 0; j < len - i - 1; j ++){
            if(test[j + 1] < test[j]){
                int temp = test[j + 1];
                test[j + 1] = test[j];
                test[j] = temp;
            }
            for(int i = 0; i < len; i ++)
                cout << test[i] << " ";
            cout << endl;
        }
    }
}

void bubbleSort_opt(int test[], int len){
    bool change = true;              // flag recording whether the last round has anything changed
    int lastPos = len - 1, k;      // record the last position that has swap operation
    while(change){
        change = false;
        for(int j = 0; j < lastPos; j ++){
            if(test[j + 1] < test[j]){
                change = true;
                k = j;
                int temp = test[j + 1];
                test[j + 1] = test[j];
                test[j] = temp;
            }
        }
        lastPos = k;
        for(int i = 0; i < len; i ++)
            cout << test[i] << " ";
        cout << endl;
    }
}

void selectSort(int test[], int len){
    int index;
    for(int i = 0; i < len; i ++){
        int min = test[i];
        for(int j = i; j < len - 1; j ++){
            if(test[j + 1] < min){
                min = test[j + 1];
                index = j + 1;
            }
        }
        int temp = test[i];
        test[i] = test[index];
        test[index] = temp;
        for(int i = 0; i < len; i ++)
            cout << test[i] << " ";
        cout << endl;
    }
}
int main(){
    int test[7] = {2,10,3,1,6,0,-9};
    for(auto i : test)
        cout << i << " ";
    cout << endl << endl;
    // insertSort(test, 7);
    selectSort(test, 7);
    // bubbleSort_normal(test, 7);
    // bubbleSort_opt(test, 7);
    // for(auto i : test){
    //     cout << i << " ";
    // }
}
