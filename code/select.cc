//
// Created by sly on 2023/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 *  思想：选择排序，每一次找出一个最大的元素，把最大的元素与最后一个元素换位置
 *  最小的元素与第一个元素换位置，然后首尾收缩
 *  时间复杂度： 好坏平均 = O(N2)
 */


void select_sort(vector<int> &vec){

    int n = vec.size();
    int begin = 0, end = n - 1;
    while(begin < end){
        int min = begin, max = begin;
        for(int i=begin; i<=end; ++i){
            if(vec[min] > vec[i])
                min = i;
            if(vec[max] < vec[i])
                max = i;
        }
        swap(vec[min], vec[begin]);
        if(max == begin)
            max = min;
        swap(vec[max], vec[end]);
        begin++;
        end--;
    }


}



int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};

    select_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}

