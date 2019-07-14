#!/usr/bin/env python
# -*- coding=utf8 -*-

#  顺序锁

import threading
class Foo:
    def __init__(self):
        self.lock1=threading.Lock()
        self.lock2=threading.Lock()
        self.lock3=threading.Lock()
        
        self.lock2.acquire()
        self.lock3.acquire()
        pass


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        self.lock1.acquire()
        
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        
        self.lock2.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        
        self.lock2.acquire()
        
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        
        self.lock3.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        
        self.lock3.acquire()
        
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        
        self.lock1.release()
