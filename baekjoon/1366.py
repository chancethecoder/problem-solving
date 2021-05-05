import sys

INF = sys.maxsize
NOTES = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']

def get_all_combinations(A, B):
    c = []

    if len(A) < 2:
        return [[(A[0], b)] for b in B]

    a, restA = A[0], A[1:]
    pairs = [(a, b) for b in B]
    c_rests = get_all_combinations(restA, B)

    for pair in pairs:
        for c_rest in c_rests:
            c.append(c_rest + [pair])

    return c

def solve(strings, chords):
    res = INF
    t = []

    # 주어진 튜닝 값으로 모든 코드 음을 연주 가능할 경우 난이도 0
    if all([string in chords for string in strings]) and all([chord in strings for chord in chords]):
        return 0

    candidates = get_all_combinations(strings, chords)

    for pairs in candidates:
        # 1. 모든 코드가 포함되어있지 않는 후보 제외하기
        seconds = [second for _, second in pairs]
        if not all([chord in seconds for chord in chords]):
            continue

        # 2. 모든 후보의 눌린 pret 번호 리스트 구하기
        prets = []
        for pair in pairs:
            closed, chord = pair
            closed_idx = NOTES.index(closed)
            chord_idx = NOTES.index(chord)

            pret = 0
            while closed_idx != chord_idx: # 음이 같아질 때 까지 다음 프렛으로 이동
                closed_idx = (closed_idx + 1) % 12
                pret += 1

            if pret > 0:
                prets.append(pret)

        # 3. 난이도의 크기를 구해서 최솟값 비교하기
        if prets:
            difficulty = max(prets) - min(prets) + 1
            # res = min(res, difficulty)
            if res > difficulty:
                res = difficulty
                t = prets

    print(t)

    return 0 if res == INF else res

if __name__ == '__main__':
    N, M = map(int, input().split())
    strings = input().split()
    chords = input().split()
    print(solve(strings, chords))