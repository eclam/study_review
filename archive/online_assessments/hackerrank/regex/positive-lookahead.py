# Source: https://www.hackerrank.com/challenges/positive-lookahead/problem
import re
# Solution:
Regex_Pattern = r'o(?=oo)'  # Do not delete 'r'.

# Given Code:
print("Number of matches :", len(re.findall(Regex_Pattern, input())))
