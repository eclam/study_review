# Source: https://www.hackerrank.com/challenges/matching-range-of-characters/problem
import re
# Solution:
Regex_Pattern = r'^[a-z][1-9][^a-z][^A-Z][A-Z]'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
