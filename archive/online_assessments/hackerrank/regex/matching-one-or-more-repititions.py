# Source: https://www.hackerrank.com/challenges/matching-one-or-more-repititions/problem
import re
# Source:
Regex_Pattern = r'^\d+[A-Z]+[a-z]+$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
