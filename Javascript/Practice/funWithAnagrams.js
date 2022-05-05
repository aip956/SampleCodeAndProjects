// Fun with Anagrams
// Given an array of strings, remove each string that is an anagram of an earlier string, then return the remaining array in sorted order.

// Example:
// Input: str = ['code', 'doce', 'ecod', 'framer', 'frame']
// Output: ['code','frame','framer']

// Logic:
// Split array by elements, sort the elements in array
  // Split each element and sort it
  // For each sorted element, is it in the TempArray?
  // If not, push it to the TempArray, and push the original element to the outputArray
  
  // TempArray will hold the temporary array with the unsorted element/words
  //outputArray will hold the solution
  // strSorted: Sort the original input (by word, split by comma)
  // for each element, sort in the element (split by '')
  // => strByEl holds each word, split
  // => origElem holds the original word, to be pushed into the output
  // => elementbrk holds the sorted word, still split
  // => element rejoins the sorted word
  // If the TempArray does not include the element (sorted word), 
  // => push it to the TempArray
  // => and then push the original word, origElem, to the output array


function funWithAnagrams(str){
      var TempArray = [];
      var outputArray = [];
      var strSorted = str.sort();
    for (i = 0; i < str.length; i++) {
      var strByEl =str[i].split(',');
      var origElem = str[i];
      var elementbrk = (str[i].split('').sort());
      var element = (elementbrk.join(''));
          if (!TempArray.includes(element)) {
        TempArray.push(element);
        outputArray.push(origElem);
       };
    }
        return(outputArray);
  }
  

  console.log(funWithAnagrams(['12345', '1234', 'hello', 'othello', 'hello']));
  
  
  