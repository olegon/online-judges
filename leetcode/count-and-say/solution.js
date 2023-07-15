/*
38. Count and Say
https://leetcode.com/problems/count-and-say/description/
*/

/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    let result = "1"

    for (let i = 1; i < n; i++) {
        result = analyse(result);
    }

    return result;
};

function analyse(number) {
    const countingDigits = [
        { digit: number[0], quantity: 1 }
    ];

    for (let i = 1; i < number.length; i++) {
        const digit = number[i];
        const lastDigitSoFar = countingDigits.at(-1);

        if (lastDigitSoFar.digit == digit) {
            lastDigitSoFar.quantity++;
        }
        else {
            countingDigits.push({ digit, quantity: 1 })
        }
    }

    return countingDigits
        .map(({ digit, quantity }) => `${quantity}${digit}`)
        .join('');
}
