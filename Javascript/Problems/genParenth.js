// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// [3, 1 1 in 2, 2 1, 1 2, 1 1 1]

var generateParenthesis = function(n) {
    var index;
    var right_par;
    var left_par;
    var par_ind;
    var left = "("
    var right = ")"
    var ind;
    var plus_right_par;
    var plus_left_par;
    var plus_par_ind1;
    output = [];
    for (index = 1; index < n; index++) {
        right_par = right.repeat(index);
        console.log("20ind:",index);
        console.log("21RtPar:",right_par);
        left_par = left.repeat(index);
        par_ind = left_par.concat(right_par);
        console.log("Par_ind",par_ind);
        // ind = index - 1;
        // plus_right_par = right.repeat(ind);
        // plus_left_par = left.repeat(ind);
        // plus_par_ind1 = plus_left_par.concat(plus_right_par);
        output.push(par_ind);
        console.log(output);
};
}
console.log(generateParenthesis(4));
// not ()))
// to be well-formed, left "(" precedes right one ")"
// if n is 2, ["()()", "(())"]
// outcomes are single sets (), nested: single/single, single nested and double
// for n = 3; 3*singles, nested of n-1 (()) and single
// for n = 4, 4 singles, n-1 nested ((())) and single, n-2 nested (()) twice, single and n-1 nested ((()))
// n: n single sets, single and n-1 nested, n-1 nested and single
// 
// index
// n single sets and index sets
// n-index nested and index
// start with empty output array
// left = "("
// right = ")"
// string.repeat(x times)
// for (index = 0; index < n; index++) {
// string of nested index and index ()
// repeat string "(" index times
// right_par = right.repeat(index)
// left_par = left.repeat(index)
// par = left_par.concat(right_par);
// 
