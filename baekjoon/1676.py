# def solve(N):
# 	t = 1
# 	res = 0
# 	for i in range(1, N + 1):
# 		t = t * i
# 		while t % 10 == 0:
# 			t = t / 10
# 			res += 1
# 		t = t % 10
# 	return res

def solve(N):
	t = 1
	res = 0
	for i in range(1, N + 1):
		t = t * i
		while t % 5 == 0:
			t = t / 5
			res += 1
		t = t % 5
	return res

if __name__ == "__main__":
	N = int(input())
	print(solve(N))