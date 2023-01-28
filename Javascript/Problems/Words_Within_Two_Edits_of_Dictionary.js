/*
Leetcode medium, https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.
*/

var twoEditWords = function(queries, dictionary) {
    solution = [];  
    for (i = 0; i < queries.length; i++) {
      for (j = 0; j < dictionary.length; j++) {
        counter = 0;   
        for (k = 0; k < queries[i].length; k++) {
            if (queries[i][k] != dictionary[j][k]) {
              counter++;
            }
        }
          if (counter <= 2) {
            solution.push(queries[i])
            break;
          }
        }// dictionary.length
      }; // for queries.length
      return(solution);
    }
  
  
  
  
  // console.log(twoEditWords(["word","note","ants","wood"], ["wood","joke","moat"]));
  // console.log(twoEditWords(["yes"], ["not"]));
  console.log(twoEditWords(["tsl","sri","yyy","rbc","dda","qus","hyb","ilu","ahd"], ["uyj","bug","dba","xbe","blu","wuo","tsf","tga"]));

