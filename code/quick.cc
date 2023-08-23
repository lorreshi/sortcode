//
// Created by 石立宇 on 2023/8/24.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 快速排序思想：每次拿第一个数值当作flag，在数组中找到比他小或者大的数字放在左右两边
 * 最后吧flag放在合适的位置 递归
 * 时间复杂度 最好nlogn 最坏n2
 *           最好的情况每次都在中间fn = 2f(n/2) + m m为平分数组话费的时间
 *           最差的情况次每次都是最小值 fn = n*（n-1）类似于冒泡算法
 *  稳定性： 不稳定
 */

// 分割数组，返回每次插入的值的位置
int part(vector<int> &vec, int left, int right){
    int flag = vec[left];
    int i = left + 1, j = right;

    while(1){
        // 找到第一个大于flag的数字
        while(i<=j && vec[i] <= flag)
            i++;
        // 找到第一个小于flag的数组
        while(i<=j && vec[j] >= flag)
            j--;
        // 不符合条件 break
        if(i>j)
            break;
        swap(vec[i], vec[j]);
    }
    // 最后一个j也是小于flag的 所以吧flag与j呼唤 保证了flag的正确位置
    vec[left] = vec[j];
    vec[j] = flag;
    return j;
}






void quick_sort(vector<int> &vec, int left, int right){
    if(left < right){
        int mid = part(vec, left, right);

        quick_sort(vec, left, mid-1);
        quick_sort(vec, mid+1, right);
    }
}


int main(){

    vector<int> arr = {3,13,37,15,27,16,48,16,57,2,46,41,9,78,58};
    vector<int> arr1 = {9,8,7,6,5,4,3,2,1};

    quick_sort(arr, 0, arr.size()-1);

    for(auto x : arr){
        cout << x << " ";
    }


    return 0;
}

