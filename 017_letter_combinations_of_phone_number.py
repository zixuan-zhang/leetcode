
"""
@ Question:
    Given a digit string, return all possible letter combinations that the
    number could represent.A mapping of digit to letters (just like on the
    telephone buttons) is given below.

    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    Note:
    Although the above answer is in lexicographical order, your answer could
    be in any order you want.
"""

class Solution(object):

    def letterCombinations(self, digits):
        """
        : type digits: str
        : rtype: List[str]
        """
        result = []
        if not digits:
            return result
        num2letter = {
                "1": "****",
                "2": "abc*",
                "3": "def*",
                "4": "ghi*",
                "5": "jkl*",
                "6": "mno*",
                "7": "pqrs",
                "8": "tuv*",
                "9": "wxyz",
                "0": "****"
                }
        digitLen = len(digits)
        cnt = pow(4, digitLen)
        for i in range(cnt):
            com = ""
            num = i
            for j in range(digitLen -1 , -1, -1):
                index = num % 4
                num = num / 4
                if digits[j] == "1" or digits[j] == "0":
                    continue
                com += num2letter[digits[j]][index]
            if com.find("*") == -1 and com[::-1] not in result:
                result.append(com[::-1])
                
        return result

    def letterCombinationsDFS(self, digits):
        """
        : type digits: str
        : rtype: List[str]
        """
        result = []
        save = ""
        if not digits:
            return result
        num2letter = {
                "0": "",
                "1": "",
                "2": "abc",
                "3": "def",
                "4": "ghi",
                "5": "jkl",
                "6": "mno",
                "7": "pqrs",
                "8": "tuv",
                "9": "wxyz",
                }
        self.dfs(result, save, digits, 0, num2letter)
        return result

    def dfs(self, result, save, digits, digitIndex, num2letter):
        if digitIndex == len(digits):
            result.append(save)
            return
        if digits[digitIndex] == "0" or digits[digitIndex] == "1":
            self.dfs(self, save, digits, digitIndex+1, num2letter)
        for i in range(len(num2letter[digits[digitIndex]])):
            save += num2letter[digits[digitIndex]][i]
            self.dfs(result, save, digits, digitIndex+1, num2letter)
            save = save[:-1]

if __name__ == "__main__":
    s = Solution()
    result = s.letterCombinations("20")
    print result
    result = s.letterCombinations("20")
    print result
    # result = s.letterCombinations("32")
    # print result
    # result = s.letterCombinations("23")
    # print result
    # result = s.letterCombinations("7")
    # print result
