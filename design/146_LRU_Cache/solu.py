
#  题目：实现一个LRU Cache，put 和 get 最好是O(1)的复杂度

#  LRU Cache，要求容量为m，当插入的数据超过容量上限后，按照访问时间顺序，覆盖旧数据，put 和 get都算更新访问时间

#  思路：dict存数据，关键在于如何构造一个数据结构，存储访问时间顺序，并且能再O(1)内更新访问时间顺序

#  第一反应是，使用一个stack，存储key，按照访问顺序，更新stack里key的排序。
#  但是有一个问题是，比如，stack为[3, 7, 1, 8], 最大容量4，然后插入数据5：2，此时，key=1，最老，应该删除它，
#  那么，如何在O(1)内，获取到stack[idx] = 1, 并把它从栈里删除？考虑使用两个栈，这样刷新的复杂度在O(1) ~ O(N)之间，N是容量

#  另一个思路是，使用OrderDict，排序字典
#  但是，time > 6%, space > 5%
from collections import OrderedDict 
class LRUCache:

    # use a queue to store turn of uesd
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.cache_size = 0
        self.cache_max_size = capacity
        

    def get(self, key: int) -> int:
        if key in self.cache:
            
            val = self.cache[key]
            
            self.cache.pop(key)
            self.cache[key] = val
            
            #print("-------get key {}:{}".format(key, val))
            #print(self.cache)
            return val
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
            self.cache[key] = value
        else:
            if self.cache_size + 1 > self.cache_max_size:
                head_key = list(self.cache.items())[0][0]
                    
                self.cache.pop(head_key)
                self.cache_size -= 1
        
            self.cache[key] = value
            self.cache_size += 1
        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
