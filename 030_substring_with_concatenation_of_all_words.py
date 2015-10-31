"""
@Question:
    You are given a string, s, and a list of words, words, that are
    all of the same length. Find all starting indices of substring(s)
    in s that is a concatenation of each word in words exactly once
    and without any intervening characters.

    For example, given:
        s: "barfoothefoobarman"
        words: ["foo", "bar"]

        You should return the indices: [0,9].
        (order does not matter).
"""

class Solution(object):
    def all_concentenation(self, words, cons, deep, con, used):
        if deep == len(words):
            cons.append(con)
        else:
            for i in range(len(words)):
                if i not in used:
                    used.append(i)
                    con += words[i]
                    self.all_concentenation(words, cons, deep+1, con, used)
                    con = con[0:len(con)-len(words[i])]
                    used.remove(i)

    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        cons = []
        deep = 0
        con = ""
        used = []
        self.all_concentenation(words, cons, deep, con, used)
        result = []
        for con in cons:
            index = s.find(con)
            if -1 != index and index not in result:
                result.append(index)
        return result

if __name__ == "__main__":
    words = ["foo"]
    s = Solution()
    result = s.findSubstring("barfoothefoobarman", words)
    print result
