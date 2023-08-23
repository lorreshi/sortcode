//
// Created by 石立宇 on 2023/8/24.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 基数排序算法思想：先以个位数的大小来对数据进行排序，接着以十位数的大小来多数进行排序，
 * 接着以百位数的大小。 就是一组有序的元素了。在以某位数进行排序的时候，是用“桶”来排序的。
 * 时间复杂度：O(k∗n)
   空间复杂度：O(k+n)
   稳定性：稳定排序
 */

// 基数排序
// 有负数的话需要进行预处理，本函数不包含预处理部分
void radix_sort(vector<int> &num) {
    int len = num.size();

    // 得到数列的最大值
    int max = num[0];
    for (int i = 1; i < len; ++i) {
        if(num[i] > max)
            max = num[i];
    }

    // 计算最大值是几位数
    int times = 1;
    while (max / 10 > 0) {
        ++times;
        max /= 10;
    }

    // 创建10个桶
    vector<int> vec;
    vector<vector<int>> bucket;
    for (int i = 0; i < 10; ++i) {
        bucket.push_back(vec);
    }

    // 进行每一趟的排序，从个位数开始排
    for (int i = 1; i <= times; i++) {
        for (int j = 0; j < len; j++) {
            // 获取每个数最后第 i 位对应桶的位置
            int radio = (num[j] / (int)pow(10,i-1)) % 10;
            // 放进对应的桶里
            bucket[radio].push_back(num[j]);
        }
        // 合并放回原数组
        int k = 0;
        for (int j = 0; j < 10; j++) {
            for (int& t : bucket[j]) {
                num[k++] = t;
            }
            //合并之后清空桶
            bucket[j].clear();
        }
    }
}


int main(){

    vector<int> arr = {14,4,1,33,127,0,11,9};
    vector<int> arr1 = {1,2,3,4,5};

    radix_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}
