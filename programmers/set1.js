function solution(arr, n) {
    var answer = false;

    arr.sort(function(a, b) {
        return a - b;
    });

    for(let l = 0, r = arr.length - 1; l < r; ) {
        const curSum = arr[l] + arr[r];
        
        if (curSum === n) {
            answer = true;
            break;
        }

        curSum > n
            ? r--
            : l++;
    }
    return answer;
}