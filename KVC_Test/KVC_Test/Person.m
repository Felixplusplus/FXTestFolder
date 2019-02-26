//
//  Person.m
//  KVC_Test
//
//  Created by Felix on 2019/2/25.
//  Copyright © 2019 Felix. All rights reserved.
//

#import "Person.h"

@implementation Person

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        _name = @"";
        _age = 0;
        _friends = @[];
    }
    
    return self;
}

- (NSString *)description {
    
    return [NSString stringWithFormat:@"- name: %@, age: %ld, friends: %@",self.name, self.age, self.friends];
}

- (void)setValue:(id)value forKey:(NSString *)key {
    
}

- (void)setValue:(id)value forKeyPath:(NSString *)keyPath {
    
}

- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    
}

- (id)valueForKey:(NSString *)key {
    return nil;
}

- (id)valueForKeyPath:(NSString *)keyPath {
    return nil;
}

- (id)valueForUndefinedKey:(NSString *)key {
    return nil;
}

//+ (BOOL)accessInstanceVariablesDirectly {
//    return false;
//}

@end
