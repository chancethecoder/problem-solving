"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3741/

We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas, decimal points, and spaces and ended up with the string s.

For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s = "(205)".
Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)

Constraints:

4 <= s.length <= 12
s[0] == '(' and s[s.length - 1] == ')'.
The rest of s are digits.
"""

class Solution:
    def ambiguousCoordinates(self, s):
        num_list = [c for c in s[1:-1]]
        amb_coordinates = []

        def get_possible_num_list(num_list):
            if len(num_list) < 2:
                return num_list

            if num_list[0] == '0':
                trailings = ''.join(num_list[1:])
                possible_num = '.'.join(['0', trailings])
                return [ possible_num ] if num_list[-1] != '0' else []

            possible_num_list = [ ''.join(num_list) ]

            for i in range(1, len(num_list)):
                decimals = ''.join(num_list[:i])
                trailings = ''.join(num_list[i:])
                possible_num = '.'.join([decimals, trailings])
                if trailings[-1] == '0': continue
                possible_num_list.append(possible_num)

            return possible_num_list

        for i in range(1, len(num_list)):
            lside_list = get_possible_num_list(num_list[:i])
            rside_list = get_possible_num_list(num_list[i:])
            if len(lside_list) * len(rside_list) < 1: continue
            for x in lside_list:
                for y in rside_list:
                    amb_coordinates.append(f"({x}, {y})")

        return amb_coordinates

solution = Solution()
print(solution.ambiguousCoordinates("(123)")) # ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
print(solution.ambiguousCoordinates("(0123)")) # ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
print(solution.ambiguousCoordinates("(00011)")) # ["(0, 0.011)","(0.001, 1)"]
print(solution.ambiguousCoordinates("(100)")) # ["(10, 0)"]
