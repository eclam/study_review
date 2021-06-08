# Source: https://www.hackerrank.com/challenges/positive-lookbehind/problem
import re
# Solution:
Regex_Pattern = r"(?<=[13579])\d"  # Do not delete 'r'.

# Given Code:
print("Number of matches :", len(re.findall(Regex_Pattern, input())))
