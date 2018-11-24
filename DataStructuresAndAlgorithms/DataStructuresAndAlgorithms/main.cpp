//
//  main.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/20.
//  Copyright © 2018 Felix. All rights reserved.
//

#include <iostream>
#include "bubble_sort.hpp"







/**
 插入排序
 
 @param nums nums
 @param size size
 */
void insert_sort(int nums[] , int size) {
    
    //  使前面部分有序 ， 并且从后面遍历出的数值中插入前面有序部分
    //  插入次数 * 选择次数 时间复杂度为 O(n^2)
    
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
    
    
    //  每次都从头乱序数组中b将最大值放在头部
    //  时间复杂度O(n^2)
    
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
    
    // 不断将步长设置为数组大小的一半 ，组内采用c插入排序 ， 重复直到步长为1
    
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
    
    cout << endl;
    
    return 0;
}


