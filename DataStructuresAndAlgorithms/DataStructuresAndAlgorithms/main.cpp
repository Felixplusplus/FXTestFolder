//
//  main.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/20.
//  Copyright © 2018 Felix. All rights reserved.
//

#include <iostream>

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
                
            //                nums[j] += nums[j + 1];
            //                nums[j + 1] = num[j] - nums[j + 1];
            //                nums[j] -= num[j + 1];
            }
        }
    }
}

void insert_sout(int nums[] , int size) {
    
    for (int i = 0; i<size; i++) {
        for (int j = i; j>0; j--) {
            if (nums[j] < nums[j-1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}

void selection_sort(int nums[] , int size) {
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    using namespace std;
    
    cout << "Fuck You!\n";
    
    int unSortArray[] = {89,74,2,1,94,32,120};
    
    int size = sizeof(unSortArray)/sizeof(unSortArray[0]);
    
    cout << "TotalCount : " << size << endl;
    
//    bubble_sort(unSortArray,size);
    insert_sout(unSortArray, size);
    
    
    for (int i = 0; i<size; i++) {
        cout << unSortArray[i] <<endl;
    }
    
    return 0;
}


