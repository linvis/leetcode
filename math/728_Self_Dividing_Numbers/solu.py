class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def not_self_dividing(num):
            j = num
            while j > 0:
                if j % 10 == 0:
                    return False
                if num % (j % 10) != 0:
                    return False
                j = int(j / 10)
            return True
        
        return list(filter(not_self_dividing, range(left, right + 1)))
