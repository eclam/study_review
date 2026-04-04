# Source: https://www.hackerrank.com/challenges/matching-same-text-again-again/problem
import re
# Solution:
Regex_Pattern = r'^([a-z])(\w)(\s)(\W)(\d)(\D)([A-Z])([a-zA-Z])([aeiouAEIOU])(\S)\1\2\3\4\5\6\7\8\9\10$'

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
