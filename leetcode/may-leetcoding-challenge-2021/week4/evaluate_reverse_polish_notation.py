"""
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3755/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Constraints:

1 <= tokens.length <= 10^4
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
"""

class Solution:
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token is '+':
                right = stack.pop()
                left = stack.pop()
                stack.append(left + right)
            elif token is '-':
                right = stack.pop()
                left = stack.pop()
                stack.append(left - right)
            elif token is '*':
                right = stack.pop()
                left = stack.pop()
                stack.append(left * right)
            elif token is '/':
                right = stack.pop()
                left = stack.pop()
                stack.append(int(left / right))
            else:
                stack.append(int(token))
        return stack.pop()

"""
solution = Solution()
print(solution.evalRPN(["2","1","+","3","*"])) # 9
print(solution.evalRPN(["4","13","5","/","+"])) # 6
print(solution.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])) # 22
"""
