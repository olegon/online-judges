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
    let lastDigit = number[0];
    let lastDigitCount = 1;
    let result = "";

    for (let i = 1; i < number.length; i++) {
        const digit = number[i];

        if (lastDigit == digit) {
            lastDigitCount++;
        }
        else {
            result += `${lastDigitCount}${lastDigit}`;

            lastDigit = digit;
            lastDigitCount = 1;
        }
    }

    result += `${lastDigitCount}${lastDigit}`;

    return result;
}
