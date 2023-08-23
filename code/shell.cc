//
// Created by 石立宇 on 2023/8/24.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 希尔排序算法思想： 一种插入排序的改进方式，提高了时间复杂度 在O(N1.3)-O(N2)之间
 * 例如每次缩小间距为2，依次递增。
 * 数组：9，8，7，6，5，4，3，2，1 ->4
 * 一次：1，2，3，4，5，8，7，6，9 ->2
 * 二次：1，2，3，4，5，6，7，8，9
 */

void shell_sort(vector<int> &vec){
    int n = vec.size();
    for(int i=n/2; i>0; i /=2){
        for(int j=i; j<n; ++j){
            //与他间隔为k的点
            int k = j - i;
            while(k>=0 && vec[k] > vec[j]){
                swap(vec[k], vec[j]);
                // k j 同时前移i个位置，比较swap之后的j与之前与他相聚i个间隔的大小
                k -= i;
                j -= i;
            }
        }
    }


}

int main(){

    vector<int> arr = {3,13,37,15,27,16,48,16,57,2,46,41,9,78,58};
    vector<int> arr1 = {9,8,7,6,5,4,3,2,1};

    shell_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }


    return 0;
}
