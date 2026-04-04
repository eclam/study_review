# Source: https://www.hackerrank.com/challenges/matching-zero-or-more-repetitions/problem
import re
# Source:
Regex_Pattern = r'^\d{2,}[a-z]*[A-Z]*$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
