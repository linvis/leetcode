
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        A = []
        head = 0
        tail = len(S)
        for c in S:
            if c == 'I':
                A.append(head)
                head += 1
            else:
                A.append(tail)
                tail -= 1
        A.append(head)        
        return A
