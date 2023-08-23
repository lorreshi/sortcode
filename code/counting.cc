//
// Created by sly on 2023/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 计数排序思想：把所有的数组中数据放入一个新开辟的数组，这个数组包括原数组
 * 最大值-最小值的所有元素，最后输出此数组
 * 使用情景： 数组最值差值不大的情况下
 * 时间复杂度 O（n+k） k为开辟数组大小
 * 空间复杂度 O（k）
 * 稳定性 稳定排序
 */

void counting_sort(vector<int> &vec){
    int n = vec.size();
    int max = vec[0], min = vec[0];
    for(int i=0; i<n; ++i){
        if(vec[i] > max)
            max = vec[i];
        if(vec[i] < min)
            min = vec[i];
    }

    vector<int> vec1(max-min+1, 0);

    for(int i=0; i<n; ++i){
        vec1[vec[i]-min]++;
    }

    // 遍历统计数组，输出结果
    int index = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        for (int j = 0; j < vec1[i]; ++j) {
            vec[index++] = i + min;
        }
    }


}


int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};

    counting_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}
