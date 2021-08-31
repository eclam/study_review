# Source: https://leetcode.com/problems/defanging-an-ip-address/submissions/

def recurseDefang(address: str) -> str:
    lenAddr = len(address)
    if lenAddr > 1:
        halfLength = int(lenAddr/2)
        lengthOfAddr = int(lenAddr)

        firstHalf = address[0:halfLength]
        secondHalf = address[halfLength:lengthOfAddr]
        firstHalf = recurseDefang(firstHalf)
        secondHalf = recurseDefang(secondHalf)

        address = firstHalf + secondHalf
    else:
        if address == '.':
            address = '[.]'

    return address

def defangIPaddr(address: str) -> str:
    temp = ""
    for i in address:
        if i != ".":
            temp += i
        else:
            temp += "[.]"
    return temp

def defangIPaddrOneLiner(address: str) -> str:
    return address.replace('.','[.]')

# if __name__ == __main__:
address = input()
print(defangIPaddr(address))
# print(recurseDefang(address))
# print(defangIPaddrOneLiner(address))