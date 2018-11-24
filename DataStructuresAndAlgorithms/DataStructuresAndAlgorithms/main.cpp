//
//  main.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/20.
//  Copyright © 2018 Felix. All rights reserved.
//

#include <iostream>


/**
 冒泡

 @param nums nums
 @param size size
 */
void bubble_sort(int nums[] , int size) {
    //    从左开始比较相邻的两个元素x和y，如果 x > y 就交换两者
    //    执行比较和交换，直到到达数组的最后一个元素
    //    重复执行1和2，直到执行n次，也就是n个最大元素都排到了最后
    
    
    //    由于我们要重复执行n次冒泡，每次冒泡要执行n次比较（实际是1到n的等差数列，也就是(a1 + an) * n / 2），也就是 O(n^2)。 空间复杂度是O(n)。
    
    for (int i = 0; i<size-1; i++) {
        for (int j = 0; j<size-i-1; j++) {
            if (nums[j]>nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                
            //                不需要tmp的方法
            //                nums[j] += nums[j + 1];
            //                nums[j + 1] = num[j] - nums[j + 1];
            //                nums[j] -= num[j + 1];
            }
        }
    }
}

/**
 插入排序
 
 @param nums nums
 @param size size
 */
void insert_sort(int nums[] , int size) {
    
    //  使前面部分有序 ， 并且从后面遍历出的数值中插入前面有序部分
    //  插入次数 * 选择次数 复杂度为 O(n^2)
    
    for (int i = 1; i < size; i++) {
        for (int j = i; j>0; j--) {
            if (nums[j] < nums[j-1]) {
                int tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            }
        }
    }
}

/**
 选择排序
 
 @param nums nums
 @param size size
 */
void selection_sort(int nums[] , int size) {
    
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (nums[j] > nums[min]) {
                min = j;
            }
        }
        
        int tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
    }
}


/**
 希尔排序 (递减增量排序法)

 @param nums nums
 @param size size
 */
void shell_sort(int nums[] , int size) {
    
    for (int gap = size >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < size; i++) {
            
            int tmp = nums[i];
            
            int j = i - gap;
            for (; j >= 0 && nums[j] > tmp; j -= gap) {
                nums[j + gap] = nums[j];
            }
            
            nums[j + gap] = tmp;
        }
    }
}

/**
 归并排序 (分治)
 
 @param nums nums
 @param size size
 */
void merge_sort(int nums[] , int size) {
    
}

/**
 快速排序
 
 @param nums nums
 @param size size
 */
void quick_sort(int nums[] , int size) {
    
}

/**
 堆排序
 
 @param nums nums
 @param size size
 */
void heap_sort(int nums[] , int size) {
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    using namespace std;
    
    int unSortArray[] = {89,74,2,1,94,32,120};
    
    int size = sizeof(unSortArray)/sizeof(unSortArray[0]);
    
    cout << "TotalCount : " << size << endl;
    
    cout << "originArray:";
    
    for (int i = 0; i<size; i++) {
        cout << unSortArray[i] << ",";
    }
    cout << endl;
    
    bubble_sort(unSortArray,size);
//    insert_sort(unSortArray, size);
//    selection_sort(unSortArray, size);
//    shell_sort(unSortArray, size);
    
    
    cout << "sortedArray:";
    
    for (int i = 0; i<size; i++) {
        cout << unSortArray[i] << ",";
    }
    
    return 0;
}


