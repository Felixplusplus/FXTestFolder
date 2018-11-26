//
//  main.cpp
//  DataStructuresAndAlgorithms
//
//  Created by Felix on 2018/11/20.
//  Copyright © 2018 Felix. All rights reserved.
//

#include <iostream>
#include "bubble_sort.hpp"
#include "insert_sort.hpp"


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
    
//    bubble_sort(unSortArray,size);
    insert_sort(unSortArray, size);
//    selection_sort(unSortArray, size);
//    shell_sort(unSortArray, size);
    
    
    cout << "sortedArray:";
    
    for (int i = 0; i<size; i++) {
        cout << unSortArray[i] << ",";
    }
    
    cout << endl;
    
    return 0;
}


