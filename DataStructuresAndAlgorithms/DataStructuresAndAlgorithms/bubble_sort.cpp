//
//  bubble_sort.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/24.
//  Copyright © 2018 Felix. All rights reserved.
//

#include "bubble_sort.hpp"

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
