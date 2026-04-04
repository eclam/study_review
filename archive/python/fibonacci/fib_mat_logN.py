# O(LogN)
class Solution:
    def fib(self, n: int) -> int:
        if(n == 0):
            return 0
        M = [[1,1],[1,0]]
        return self.to_the_power(M,n-1)[0][0]

    def to_the_power(self, M, n):
        if(n==0 or n==1):
            return M;

        M = self.to_the_power(M, n//2)
        M = self.multiply_fib(M, M)

        if(n%2 != 0):
            M = self.multiply_fib(M, [[1,1],[1,0]])

        return M

    def multiply_fib(self, A, M):
        a = (A[0][0]*M[0][0]) + (A[0][1]*M[1][0])
        b = (A[0][0]*M[0][1]) + (A[0][1]*M[1][1])

        c = (A[1][0]*M[0][0]) + (A[1][1]*M[1][0])
        d = (A[1][0]*M[0][1]) + (A[1][1]*M[1][1])

        return [[a,b],[c,d]]

if __name__ == "__main__":
    n = 30
    soln = Solution()
    print(soln.fib(n))