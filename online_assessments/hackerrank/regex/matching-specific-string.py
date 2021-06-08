# Source: https://www.hackerrank.com/challenges/matching-specific-string/problem
import re

# Solution:
Regex_Pattern = r'hackerrank'

# Given Code:
Test_String = input()
match = re.findall(Regex_Pattern, Test_String)
print("Number of matches :", len(match))
