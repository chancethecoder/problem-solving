def solve(candidates):
	all_sum = sum(candidates)

	for i in range(8):
		for j in range(i+1, 9):
			exclusive_sum = candidates[i] + candidates[j]
			if all_sum - exclusive_sum == 100:
				winners = []

				for k in range(9):
					if k != i and k != j:
						winners.append(candidates[k])

				winners.sort()

				for winner in winners:
					print(winner)

				return

if __name__ == '__main__':
	candidates = []
	for _ in range(9):
		candidates.append(int(input()))
	solve(candidates)