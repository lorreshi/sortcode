//
// Created by 石立宇 on 2023/8/24.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 *归并排序算法思想：分治法，将数组拆分成无数个小数组，让无数个小数组合并成一个有序的大数组
 * 步骤：数组合并 + 拆分数组
 * 时间复杂度： nlog2n
 * 方法：递归 非递归
 *
 */
void merge(vector<int> &num, int left, int mid, int right){
    vector<int> leftSubArray(num.begin() + left, num.begin() + mid + 1);
    vector<int> rightSubArray(num.begin() + mid + 1, num.begin() + right + 1);

    int idxLeft = 0, idxRight = 0;
    // 在数组最后插入int类型能表示的最大值
    leftSubArray.insert(leftSubArray.end(), numeric_limits<int>::max());
    rightSubArray.insert(rightSubArray.end(), numeric_limits<int>::max());

    // 已有元素不可能大于int能表示的最大值，因此能覆盖两个数组中的所有元素
    for (int i = left; i <= right; i++) {
        if (leftSubArray[idxLeft] < rightSubArray[idxRight]) {
            num[i] = leftSubArray[idxLeft];
            idxLeft++;
        } else {
            num[i] = rightSubArray[idxRight];
            idxRight++;
        }
    }

}

void merge_sort(vector<int> &vec){
    int n = vec.size();
    // 拆分数组
    for(int i=1; i<n; i+=i){
        int left = 0;
        int mid = left + i - 1;
        int right = mid + i;
        // 合并数组
        while(right < n){
            merge(vec, left, mid, right);
            left = right + 1;
            mid = left + i - 1;
            right = mid + i;
        }
        // 还有一些被遗漏的数组没合并，因为不可能每个子数组的大小都刚好为 i
        if (left < n && mid < n) {
            merge(vec, left, mid, n - 1);
        }
    }

}

//递归
void merge_sort1(vector<int> &vec, int left, int right){
    if(left >= right)
        return ;
    int mid = left + (right - left)/2;
    merge_sort1(vec, left, mid);
    merge_sort1(vec, mid+1, right);
    merge(vec, left, mid, right);
}


int main(){

    vector<int> arr = {3,13,37,15,27,16,48,16,57,2,46,41,9,78,58};
    vector<int> arr1 = {9,8,7,6,5,4,3,2,1};

    merge_sort(arr);
    merge_sort1(arr1, 0, arr1.size()-1);

    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;
    for(auto y : arr1){
        cout  << y << " ";
    }


    return 0;
}
