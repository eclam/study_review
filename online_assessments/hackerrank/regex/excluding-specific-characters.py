# Source : https://www.hackerrank.com/challenges/excluding-specific-characters/problem
import re
# Solution:
Regex_Pattern = r'^\D[^aeiou][^bcDF]\S[^AEIOU][^.,]$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
