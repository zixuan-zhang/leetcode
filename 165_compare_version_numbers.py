"""
@Question:
    Compare two version numbers version1 and version2.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.
    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth
    second-level revision of the second first-level revision.

    Here is an example of version numbers ordering:
        0.1 < 1.1 < 1.2 < 13.37
"""

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """

        versionList1 = version1.split(".")
        versionList2 = version2.split(".")
        len1 = len(versionList1)
        len2 = len(versionList2)
        i = 0
        j = 0
        while i < len1 and j < len2:
            if int(versionList1[i]) < int(versionList2[j]):
                return -1
            elif int(versionList1[i]) > int(versionList2[j]):
                return 1
            i += 1
            j += 1

        while i < len1:
            if int(versionList1[i]) != 0:
                return 1
            i += 1

        while j < len2:
            if int(versionList[i]) != 0:
                return -1
            j += 1

        return 0
