// https://programmers.co.kr/learn/courses/30/lessons/12923?language=javascript#

function solution(begin, end) {
    var answer = [];
    const len = end - begin + 1;
    const largestDivisor = (number) => {
        const squareRoot = Math.sqrt(number);

        for (let i = 2; i <= squareRoot; i++) {
            if (number % i === 0)
                return number / i;
        }

        return 1;
    }

    // O(1000 * log(n))
    for(let i = 0; i < len; i++) {
        const idx = begin + i;

        answer[i] = idx === 1
            ? 0
            : largestDivisor(idx);
    }

    return answer;
}