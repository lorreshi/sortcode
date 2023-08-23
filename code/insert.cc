//
// Created by sly on 2023/8/24.
//


#include <iostream>
#include <vector>
using namespace std;

/*
 * 插入排序思想： 每次从后面拿一个与前面已经排序的比较，如果小于前面的则插入进去
 */


void insert_sort(vector<int> &vec){
    int n = vec.size();

    for(int i=1; i<n; ++i){
        for(int j=i; j>0; --j){
            if(vec[j-1] > vec[j])
                swap(vec[j], vec[j-1]);
            else
                break;
        }

    }

}



int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};

    insert_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }


    return 0;
}
