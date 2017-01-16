'''
word = "Bulbasaur"

def solve(str, cat):
    lstr = len(str)
    lcat = len(cat)
    lword = len(word)

    for i in range(lstr):
        if str[i] == word[lcat % lword]:
            cat += str[i]
            next_str = str[:i] + str[i+1:]
            print(next_str + "/" + cat)
            return solve(next_str, cat)

    return len(cat) / lword

print(solve(raw_input(), ""))
'''

def solve(str):
    dic = {c: 0 for c in "Bulbasaur"}
    for c in str:
        if c in dic: dic[c] += 1
    for c in "ua": dic[c] = dic[c] / 2
    return min(dic.values())

print(solve(raw_input()))
