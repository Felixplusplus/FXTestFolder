//: Playground - noun: a place where people can play

import Cocoa

func sort_insert(originArray:[Int]) -> [Int] {

    return originArray.sorted(by: { (x, y) -> Bool in
        return x>y
    })
//    var sortedArray = [Int]()
//
//    for item in originArray {
//        if sortedArray.count == 0 {
//            sortedArray.insert(item, at: 0)
//        }else {
//
//        }
//    }
//
//    return sortedArray
}

let unSortedArray = [99,51,6,88,27,128,60]

sort_insert(originArray: unSortedArray)
