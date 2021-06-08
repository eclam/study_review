# Source: https://www.hackerrank.com/challenges/matching-specific-characters/problem
import re
# Solution:
Regex_Pattern = r'^[1-3][0-2][xs0][30Aa][xsu][.,]$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
