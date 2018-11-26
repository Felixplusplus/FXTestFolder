//
//  insert_sort.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/26.
//  Copyright © 2018 Felix. All rights reserved.
//

#include "insert_sort.hpp"

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
