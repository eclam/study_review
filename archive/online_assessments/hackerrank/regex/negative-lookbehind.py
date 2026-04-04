# Source: https://www.hackerrank.com/challenges/negative-lookbehind/problem
import re
# Solution:
Regex_Pattern = r"(?<![aeiouAEIOU])."  # Do not delete 'r'.

# Given Code:
print("Number of matches :", len(re.findall(Regex_Pattern, input())))
