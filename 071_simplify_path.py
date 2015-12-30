#! coding:utf-8
"""
Question:
    Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
    click to show corner cases.

    Corner Cases:
    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together,
    such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
"""

class Solution(object):

    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        dirList = path.split("/")
        stack = []
        for _dir in dirList:
            if not _dir:
                continue
            elif "." == _dir:
                continue
            elif ".." == _dir:
                if len(stack) != 0:
                    stack.pop()
            else:
                stack.append(_dir)
        return "/" + "/".join(stack)

if __name__ == "__main__":
    s = Solution()
    result = s.simplifyPath("/home//foo/")
    print result
