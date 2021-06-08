# Source : https://www.hackerrank.com/challenges/matching-x-repetitions/problem
import re
# Solution:
Regex_Pattern = r'^[A-Za-z02468]{40}([13579]|\s){5}$'  # Do not delete 'r'.

# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
