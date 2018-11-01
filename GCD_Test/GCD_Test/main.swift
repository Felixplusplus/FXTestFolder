//
//  main.swift
//  GCD_Test
//
//  Created by Felix on 2018/9/12.
//  Copyright © 2018年 Felix. All rights reserved.
//

import Foundation

DispatchQueue.main.sync {
    print("log something")
}

//let group = DispatchGroup()
//
//let q = DispatchQueue(label: "com.felix.felix", attributes: DispatchQueue.Attributes.concurrent)
//
//let item1 = DispatchWorkItem {
//    (1...5).forEach({ i in
//        print("🍎 \(Thread.current) + \(i)")
//    })
//}
//
//let item2 = DispatchWorkItem {
//    (6...10).forEach({ i in
//        print("🍇 \(Thread.current) + \(i)")
//    })
//}
//
//
//q.async(execute: item1)
//
//q.async(execute: item2)
//
//(11...15).forEach({ i in
//    print("🍌 \(Thread.current) + \(i)")
//})
