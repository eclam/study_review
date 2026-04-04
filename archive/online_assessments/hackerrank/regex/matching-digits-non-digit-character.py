# Source: https://www.hackerrank.com/challenges/matching-digits-non-digit-character/problem
import re
# Solution:
Regex_Pattern = r"\d{2}\D\d{2}\D\d{4}"  # Do not delete 'r'.


# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
