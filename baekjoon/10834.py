def solve(belts):
    speed = 1
    fliped = 0

    for belt in belts:
        a, b, flip = belt
        speed = int(speed * b)
        speed = int(speed / a)
        fliped = (fliped + flip) % 2

    return " ".join([str(fliped), str(speed)])

if __name__ == "__main__":
    M = int(input())
    belts = []

    for _ in range(M):
        belts.append(map(int, input().split()))

    print(solve(belts))