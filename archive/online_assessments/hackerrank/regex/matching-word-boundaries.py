# Source: https://www.hackerrank.com/challenges/matching-word-boundaries/problem
import re
# Source:
Regex_Pattern = r'\b[aeiouAEIOU][a-zA-Z]*\b'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
