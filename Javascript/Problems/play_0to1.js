// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// Leetcode medium


function findWinners (matches) {
    let winners = new Array(100001).fill(0);
    let losers = new Array(100001).fill(0);
    let i = 0;
    let output = [[],[]];

    // For each element pair in matches, add to winners and losers array
    for (i = 0; i < matches.length; i++) {
        // console.log(matches[i][0]);
        winners[matches[i][0]] ++;
        losers[matches[i][1]] ++;
    }

    // for each winner and loser array, find where there are sole winners and loss = 1. Push into the output object
    for (i = 0; i < winners.length; i++) {
        if (winners[i] > 0 && losers[i] == 0) {
            // console.log("16",i);
            output[0].push(i);
            // console.log(output);
        }
        if (losers[i] == 1) {
            // console.log("21",i);
            output[1].push(i);
            // console.log(output);
        }
    }
return output;
}

matches = [[1,100000]]
// matches = [[2,3],[1,3],[5,4],[6,4]]
// matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]];
console.log(findWinners(matches));