//
//  main.m
//  KVC_Test
//
//  Created by Felix on 2019/2/25.
//  Copyright © 2019 Felix. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Person *Alice = Person.new;
        Alice.name = @"Alice";
        Alice.age = 18;
        Alice.friends = @[];
        
        Person *Bob = Person.new;
        [Bob setValue:@"Bob" forKey:@"name"];
        [Bob setValue:@(28) forKey:@"age"];
        [Bob setValue:@[Alice] forKey:@"friends"];
        
        
//        [Bob setValue:nil forKey:@"friends"];
        
        NSLog(@"%@",@[Alice,Bob]);
    }
    return 0;
}
