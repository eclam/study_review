# O(N) time
class Solution:
    M = [[1,1],[1,0]]

    def multiply_fib(self, A, n):
        if(n == 0):
            return  A[0][0]

        a = (A[0][0]*self.M[0][0]) + (A[0][1]*self.M[1][0])
        b = (A[0][0]*self.M[0][1]) + (A[0][1]*self.M[1][1])
        c = (A[1][0]*self.M[0][0]) + (A[1][1]*self.M[1][0])
        d = (A[1][0]*self.M[0][1]) + (A[1][1]*self.M[1][1])

        A = [[a,b],[c,d]]
        return self.multiply_fib(A, n-1)

    def fib(self, n: int) -> int:
        if(n == 0):
            return 0
        elif (n == 1):
            return 1

        return self.multiply_fib(self.M,n-2)

if __name__ == "__main__":
    n = 30
    soln = Solution()
    print(soln.fib(n))
