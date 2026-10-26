class Solution(object):
    def readBinaryWatch(self, turnedOn):
        """
        :type turnedOn: int
        :rtype: List[str]
        """
        result = []

        for h in range(12):
            for m in range(60):
                if (bin(h).count('1') + bin(m).count('1')) == turnedOn:
                    time_str = str(h) + ":" + (str(m) if m >= 10 else "0" + str(m))
                    result.append(time_str)
                    
        return result
