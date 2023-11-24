class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        adj = {}

        for i in range(len(manager)):
            if manager[i] == -1:
                continue
            if manager[i] in adj:
                adj[manager[i]].append(i)
            else:
                adj[manager[i]] = [i]

        x = []
        maxT = informTime[headID]
        x.append([headID,0])

        while x:
            [i,t] = x.pop(0)

            t = t + informTime[i]

            maxT = max(t, maxT)
            if i in adj:
                for c in adj[i]:
                    x.append([c,t])

        return maxT
    

Solution().numOfMinutes( n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0])