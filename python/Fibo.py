def recurFibo(n):
#递归函数输出斐波拉契数列
  if n <= 1:
    return 1
  else:
    return (recurFibo(n-1) + recurFibo(n-2))

m = int(input('input a number n:'))
for i in range(m):
    print(recurFibo(i))