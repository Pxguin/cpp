numbers = list(map(int, input().split(" ")))
abc = max(numbers)
a = min(numbers)
numbers.remove(a)
b = min(numbers)
print(a,b,abc-(a+b))