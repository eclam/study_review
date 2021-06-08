# Source : https://www.hackerrank.com/challenges/matching-start-end/problem
import re
# Solution:
Regex_Pattern = r"^\d{1}\w{4}\.{1}$"

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
