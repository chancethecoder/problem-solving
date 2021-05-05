def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] > target:
            high = mid - 1
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            low = mid + 1
    return -1

def solve(results, answers):
    res = []

    results.sort()

    for answer in answers:
        bs = binary_search(results, answer)
        res.append(1 if bs != -1 else 0)

    for e in res:
        print(e)

if __name__ == '__main__':
    TC = int(input())

    for _ in range(TC):
        N = int(input())
        results = [int(e) for e in input().split()]
        M = int(input())
        answers = [int(e) for e in input().split()]
        solve(results, answers)