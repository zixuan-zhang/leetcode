
class Solution(object):
    def threeSum(self, nums):
        """
            :type nums: List[int]
            :rtype: List[List[int]]
        """
        result = []
        unique_nums = []
        num_map = {}
        triple_set = []
        for num in nums:
            if num in num_map:
                num_map[num] += 1
            else:
                num_map[num] = 1
                unique_nums.append(num)

        unique_nums = sorted(unique_nums)

        for i in range(len(unique_nums)):
            if num_map[unique_nums[i]] > 1:
                flag = i
            else:
                flag = i + 1
            for j in range(flag, len(unique_nums)):
                temp = 0 - unique_nums[i] - unique_nums[j]
                group = []
                if ( (temp == unique_nums[i] and temp == unique_nums[j] and num_map[temp] >= 3) or \
                        (temp == unique_nums[i] and temp != unique_nums[j] and num_map[temp] >= 2) or \
                        (temp != unique_nums[i] and temp != unique_nums[j] and temp in num_map) ):
                    group.append(temp)
                    group.append(unique_nums[i])
                    group.append(unique_nums[j])
                    group = sorted(group)

                    triple = ','.join([str(num) for num in group])
                    if triple not in triple_set:
                        triple_set.append(triple)
                        result.append(group)
        return result

if __name__ == "__main__":
    s = Solution()
    nums = [-1, 0, 1, 2, -1, 4]
    res = s.threeSum(nums)
    print res
