n = int(input())

def fib(n) :
    a, b = 1, 2

    for i in range(n - 1) :
        a, b = b, a + b
    return a

print(fib(n))