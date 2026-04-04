# Source: https://www.hackerrank.com/challenges/alternative-matching/problem
import re
# Solution:
Regex_Pattern = r'^(Mr\.|Mrs\.|Ms\.|Dr\.|Er\.)[a-zA-Z]+$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
