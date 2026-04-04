# Source: https://www.hackerrank.com/challenges/matching-anything-but-new-line
import sys
import re

# Solution:
regex_pattern = r"^((.){1,3}\.{1}){3}(.{1,3})$"

# Given Code:
test_string = input()
match = re.match(regex_pattern, test_string) is not None
print(str(match).lower())
