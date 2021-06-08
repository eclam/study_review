# Source: https://www.hackerrank.com/challenges/negative-lookahead/problem
import re

# Solution:
Regex_Pattern = r"(.)(?!\1)"

# Given Code:
print("Number of matches :", len(re.findall(Regex_Pattern, input())))
