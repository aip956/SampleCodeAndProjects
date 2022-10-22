// https://leetcode.com/problems/bulls-and-cows/
// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

// Input: secret = "1123", guess = "0111"
// Output: "1A1B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1123"        "1123"
//   |      or     |
// "0111"        "0111"
// Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
 var getHint = function(secret, guess) {
    let guessArr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    let secArr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    let i = 0; // digit
    let ind = 0 // index of secret, guess
    let index = 0;
    let x = 0; // bulls, exact match
    let indexes = 0; // index of arrays to compare
    let matches = 0; // matching numbers
    let y = 0; // cows, inexact match
  
    // if exact match, record as exact, add to x (bulls)
    for (ind = 0; ind < secret.length; ind++) {
      if (secret[ind] == guess[ind]) {
      x ++;
      }; // closes if
    }; // closes for
    // Check for each digit in the secret and guess; if match add to digit arrays
    for (i = 0; i < 10; i++) {
      for (index = 0; index < secret.length; index++) {
      if (i == secret[index]) {
        secArr[i]++;
        } // closes if
      if (i == guess[index]) {
        guessArr[i]++;
        } // closes if
      } // closes for index
    } // closes for i
  
    // find matches between arrays; minimum of the number of matches for a digit
    for (indexes = 0; indexes < 10; indexes ++) {
      if (secArr[indexes] > 0 && guessArr[indexes] > 0) {
        matches += Math.min(secArr[indexes],guessArr[indexes]);
      } // closes if
    } // closes for
      
  y = matches - x;
  return(`${x}A${y}B`);
  };

input1 = "1123";
input2 = "0111";
  console.log(getHint(input1, input2));