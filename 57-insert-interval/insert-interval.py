class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        new_start = newInterval[0]
        new_end = newInterval[1]

        i = 0
        n = len(intervals)
        output = []

        # add all the intervals that come before the new interval
        while i < n and new_start > intervals[i][0]:
            # print(f"the output is {output}")
            output.append(intervals[i])
            # intervals_i = intervals[i]
            # print(f"The intervals[i] is {intervals_i}")
            i +=1
            # print(f"Current output {output}")

        # merge the newInterval with last interval if nessary
        if not output or output[-1][1] < new_start:
            output.append(newInterval)
        else:
            output[-1][1] = max(output[-1][1], new_end)

        while i < n:
            start, end = intervals[i]
            # print(f"start: {start}")
            # print(f"end: {end}")

            if output[-1][1] < start:
                output.append([start, end])
            else:
                output[-1][1] = max(output[-1][1], end)
            i+=1

        return output
            