
题目：设计一个栈，要求获取栈中的最小值的复杂度是O(1)

思路：两个栈，一个存数据，一个存最小值

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)
            
        self.stack.append(x)
        

    def pop(self) -> None:
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop(-1)
            
        return self.stack.pop(-1)
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min_stack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
