// https://programmers.co.kr/tryouts/3923/challenges/11576?language=javascript

function solution(arr) {
    var answer = true;

    arr.sort(function(a, b) {
        return a - b;
    });
    
    for(let i = 0; i < arr.length; i++) {
        if (arr[i] !== i + 1) {
            answer = false;
            break;
        }
    }
    
    return answer;
}