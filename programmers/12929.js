// https://programmers.co.kr/learn/courses/30/lessons/12929?language=javascript

function solution(n) {
    const rec = (l = 0, r = 0, acc = 0) => {
        if (acc < 0 || acc > n) return 0;
        if (l + r === 2 * n) {
            return acc === 0 ? 1 : 0;
        }

        let ret = rec(l + 1, r, acc + 1) + rec(l, r + 1, acc - 1);
        return ret;
    }

    return rec();
}
