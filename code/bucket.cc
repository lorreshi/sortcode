//
// Created by sly on 2023/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 桶排序就是把最大值和最小值之间的数进行瓜分，
 * 例如分成 10 个区间，10个区间对应10个桶，
 * 我们把各元素放到对应区间的桶中去，再对每个桶中的数进行排序，可以采用归并排序、
 * 快速排序等方法。之后每个桶里面的数据就是有序的了，按顺序遍历各桶即可得到排序序列。
 * 桶排序也可用于浮点数排序
 * 时间复杂度 O（n+k）
 * 空间复杂度 O（k）
 * 稳定性 稳定
 */

// 桶排序
// 有负数的话需要进行预处理，本函数包含预处理部分
void bucket_sort(vector<int> &num) {
    int len = num.size();

    // 得到数列的最大最小值
    int max = num[0], min = num[0];
    for(int i = 1; i < len; ++i) {
        if(num[i] > max)
            max = num[i];

        if (num[i] < min)
            min = num[i];
    }

    // 计算桶的数量并初始化
    int bucketNum = (max - min) / len + 1;
    vector<int> vec;
    vector<vector<int>> bucket;
    for (int i = 0; i < bucketNum; ++i)
        bucket.push_back(vec);

    // 将每个元素放入桶
    for (int i = 0; i < len; ++i) {
        // 减去最小值，处理后均为非负数
        int pos = (num[i] - min) / len;
        bucket[pos].push_back(num[i]);
    }

    // 对每个桶进行排序，此处可选择不同排序方法
    for (int i = 0; i < bucket.size(); ++i)
        sort(bucket[i].begin(), bucket[i].end());

    // 将桶中的元素赋值到原序列
    int index = 0;
    for (int i = 0; i < bucketNum; ++i)
        for(int j = 0; j < bucket[i].size(); ++j)
            num[index++] = bucket[i][j];
}





int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};

    bucket_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}
