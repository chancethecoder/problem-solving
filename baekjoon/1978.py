raw_input()
arr = [int(e) for e in raw_input().split()]

prime = []
for i in range(2, max(arr) + 1):
    isPrime = True
    for p in prime:
        if i % p == 0:
            isPrime = False
            break
    if isPrime:
        prime.append(i)

print len(filter(lambda x: x in prime, arr))
