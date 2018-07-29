// https://programmers.co.kr/learn/courses/30/lessons/12902?language=javascript

function solution(n) {
    const MOD = 1000000007;
    const memo = new Array(n + 1).map(e => 0);

    memo[0] = 1;
    memo[2] = 3;

    for (let i = 4; i <= n; i += 2) {
        memo[i] = (memo[i - 2] * 3) % MOD;

        for (let j = i - 4; j >= 0; j-= 2) {
            memo[i] = (memo[i] + memo[j] * 2) % MOD;
        }
    }

    return memo[n];
}