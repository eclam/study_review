# Source: https://www.hackerrank.com/challenges/capturing-non-capturing-groups/problem
import re
# Solution:
Regex_Pattern = r'(ok){3,}'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
