
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


