//
// Created by sly on 2023/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 *  时间复杂度： O(n∗logn)
    空间复杂度： O(1)
    稳定性：不稳定排序
 */

/**
 * 调整节点操作，大根队把大节点调上来，小根队同理
 * @param vec 数组
 * @param start 子节点位置
 * @param end 数组最后一个节点位置
 */
void downAdjust(vector<int> &num, int parent, int n) {
    // 临时保存要下沉的元素
    int temp = num[parent];
    // 定位左孩子节点的位置
    int child = 2 * parent + 1;

    // 开始下沉
    while (child <= n) {
        // 如果右孩子节点比左孩子大，则定位到右孩子
        if (child + 1 <= n && num[child] < num[child + 1])
            ++child;

        // 如果孩子节点小于或等于父节点，则下沉结束
        if (num[child] <= temp)
            break;

        // 父节点进行下沉
        num[parent] = num[child];
        parent = child;
        child = 2 * parent + 1;
    }
    num[parent] = temp;
}

// 堆排序
void heap_sort(vector<int> &num) {
    int len = num.size();

    // 构建大顶堆
    for (int i = (len - 2) / 2; i >= 0; --i) {
        downAdjust(num, i, len - 1);
    }

    // 进行堆排序
    for (int i = len - 1; i >= 1; --i) {
        // 把堆顶元素与最后一个元素交换
        swap(num[0], num[i]);
        // 把打乱的堆进行调整，恢复堆的特性
        downAdjust(num, 0, i - 1);
    }
}



int main(){

    vector<int> arr = {14,4,1,33,127,0,-1,9};
    vector<int> arr1 = {1,2,3,4,5};

    heap_sort(arr);

    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}
