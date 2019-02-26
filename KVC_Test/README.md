Key-Value-Coding

NSKeyValueCoding.h

```objectivec

@interface NSObject(NSKeyValueCoding)

@interface NSArray<ObjectType>(NSKeyValueCoding)

@interface NSDictionary<KeyType, ObjectType>(NSKeyValueCoding)

@interface NSMutableDictionary<KeyType, ObjectType>(NSKeyValueCoding)

@interface NSOrderedSet<ObjectType>(NSKeyValueCoding)

@interface NSSet<ObjectType>(NSKeyValueCoding)

```
```objectivec
<!-- 直接访问实例变量 -->
@property (class, readonly) BOOL accessInstanceVariablesDirectly;
```


- (nullable id)valueForKey:(NSString *)key;

- (void)setValue:(nullable id)value forKey:(NSString *)key;

- (BOOL)validateValue:(inout id _Nullable * _Nonnull)ioValue forKey:(NSString *)inKey error:(out NSError **)outError;

- (NSMutableArray *)mutableArrayValueForKey:(NSString *)key;

- (NSMutableOrderedSet *)mutableOrderedSetValueForKey:(NSString *)key

- (NSMutableSet *)mutableSetValueForKey:(NSString *)key;

- (nullable id)valueForKeyPath:(NSString *)keyPath;
  
- (void)setValue:(nullable id)value forKeyPath:(NSString *)keyPath;
  
- (BOOL)validateValue:(inout id _Nullable * _Nonnull)ioValue forKeyPath:(NSString *)inKeyPath error:(out NSError **)outError;
  
- (NSMutableArray *)mutableArrayValueForKeyPath:(NSString *)keyPath;
  
- (NSMutableOrderedSet *)mutableOrderedSetValueForKeyPath:(NSString *)keyPath;
  
- (NSMutableSet *)mutableSetValueForKeyPath:(NSString *)keyPath;

- (nullable id)valueForUndefinedKey:(NSString *)key;

- (void)setValue:(nullable id)value forUndefinedKey:(NSString *)key;

- (void)setNilValueForKey:(NSString *)key;

- (NSDictionary<NSString *, id> *)dictionaryWithValuesForKeys:(NSArray<NSString *> *)keys;

- (void)setValuesForKeysWithDictionary:(NSDictionary<NSString *, id> *)keyedValues;

