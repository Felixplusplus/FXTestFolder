//
//  shell_sort.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/26.
//  Copyright © 2018 Felix. All rights reserved.
//

#include "shell_sort.hpp"

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
