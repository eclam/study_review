# Source: https://www.hackerrank.com/challenges/matching-word-non-word
import re
# Solution:
Regex_Pattern = r"\w{3}\W{1}\w{10}\W{1}\w{3}"


# Given Code:
print(str(bool(re.search(Regex_Pattern, input()))).lower())
