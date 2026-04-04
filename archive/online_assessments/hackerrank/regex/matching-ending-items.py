# Source: https://www.hackerrank.com/challenges/matching-ending-items/problem
import re
# Source:
Regex_Pattern = r'^[A-Za-z]*s$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
