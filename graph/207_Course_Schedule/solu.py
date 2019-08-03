
#  题目：规则，[0,1], 先上课程1，在上课程0，检查所有规则，是否出现[0,1][1,0]互斥导致上不了课的情况

#  思路：所有的课程规则，可以构成多个图，检查每个图中，是否存在回路

#  按照规则，构建图，[0,1]，1->0，

#  然后DFS搜索图中是否有回路
#  这里需要注意的一个是，它所有的规则，可能是构成了多个子图，每个图间不相接，因此，在遍历完一个子图后，
#  把它从图里删掉

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {}

        for pre in prerequisites:
            for i in range(len(pre) - 1, 0, -1):
                graph.setdefault(pre[i], []).append(pre[i - 1])

        while graph:
            seen = []
            stack = []
            path = [list(graph.keys())[0]]
            root = None

            while path:

                node = path.pop(0)

                if node in seen: 
                    return False
                seen.append(node)

                if node not in graph:
                    if not stack:continue
                    root = stack.pop(-1)
                    while seen.pop(-1) != root:
                        pass
                    if root in stack:
                        seen.append(root)

                    continue

                nodes = graph[node]

                del graph[node]

                if len(nodes) > 1:
                    for i in range(len(nodes)):
                        stack.append(node)

                for n in nodes:
                    path = [n] + path

        return True  

