count = [0] * 100
numbers = map(int, input().split())
for number in numbers:
    count[number] += 1
if 1 in count:
    print(count.index(1))
else:
    print('yes')
