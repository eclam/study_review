# Source: https://www.hackerrank.com/challenges/matching-whitespace-non-whitespace-character/problem
import re
# Solution:
Regex_Pattern = r"\S{2}\s{1}\S{2}\s{1}\S{2}"  # Do not delete 'r'.


# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())

