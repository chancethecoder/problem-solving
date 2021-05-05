def solve(S):
    length = len(S)
    slice_idx = int(length / 3)

    for cur_slice_idx in range(slice_idx, 0, -1):
        prefix_start = 0
        prefix_end = cur_slice_idx
        suffix_start = length - cur_slice_idx
        suffix_end = length

        prefix = S[prefix_start:prefix_end]
        suffix = S[suffix_start:suffix_end]

        if prefix == suffix:
            substring = S.find(prefix, prefix_end, suffix_start)
            if substring != -1:
                return prefix

    return -1

if __name__ == '__main__':
    T = int(input())

    for i in range(T):
        S = input()
        print(f'Case {i + 1}: {solve(S)}')