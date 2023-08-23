//
// Created by sly on 2023/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 平均复杂度 O(N2) 最好最坏 O(N2) 需要优一下，因为若果是已经排序好了的数组
 * 在进行冒泡就没有意义了，但是这个程序不管是否排序好都是N2 加一个标志位
 * 如果数组已经顺序了 内循环的flag将不会变成true 程序走到判断flag直接返回，
 * 此时最好的的时间复杂度位O(N)
 */

void bubble_sort(vector<int> &vec){
    int n = vec.size();
    bool flag;
    for(int i=0; i<n; ++i){
        // 标志位
        flag = false;
        for(int j=i+1; j<n; ++j){
            if(vec[j] <= vec[i]){
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }

}


int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};
    bubble_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}
