// Your job is to write an algorithm that calculates a simplified version of a Levenshtein number between two words.

// This version of a Levenshtein number is simple: it's a value that represents how similar two given strings are.
// It is found by comparing two strings and returning the difference between them. (For information, the Levenshtein number is a real concept but we've simplified it a bit for the purposes of this exercise.)

// LOGIC
// Check number of elements in each string
// Are they the same upper and lower case? => convert to uppercase?, s1.toUpperCase()
// If string lengths not equal, return -1
// If strings are empty, return 0
// Iterate over length of string, 
// is element same in each array?
// If yes, return, if no, add 1 to a constant
// does it work if the elements are characters and numbers?


function my_levenshtein(s1, s2) {
    s1 = s1.toUpperCase();
    s2 = s2.toUpperCase();
    diff = 0;
    // console.log(s1);
    // console.log(s2);
    // console.log(s1.length);
if (s1.length != s2.length) {
    return -1;
} else for (i = 0; i < s1.length; i++) {
    if (s1[i] !== s2[i]) {
        diff ++;
        // console.log(diff);
    }

    // console.log(s1[i]);
    // console.log(s2[i]);
}
return diff;
}

console.log(my_levenshtein("ggactga", "GGACTGA"));
// console.log(my_levenshtein("GGACTGA", "GGACTGA"));
// console.log(my_levenshtein("ACCAGGG", "ACTATGG"));
// console.log(my_levenshtein("GGACGGATTCTG", "AGG"));
// console.log(my_levenshtein("",""));
// console.log(my_levenshtein("**&&!@#","**&&!@1"));