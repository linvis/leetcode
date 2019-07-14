#!/usr/bin/env python
# -*- coding=utf8 -*-

#  很简单，两个顺序锁

import threading
class FooBar:
    def __init__(self, n):
        self.n = n
        self.lock1 = threading.Lock()
        self.lock2 = threading.Lock()
        
        self.lock2.acquire()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            
            self.lock1.acquire()
            
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            
            self.lock2.release()
            


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            self.lock2.acquire()
            
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            
            self.lock1.release()
