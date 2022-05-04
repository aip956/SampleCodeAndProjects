function funWithAnagrams(str){
    // console.log(str);
      var TempArray = [];
      var outputArray = [];
      var strSorted = str.sort();
    // console.log(strSorted);
    for (i = 0; i < str.length; i++) {
      var strByEl =str[i].split(',');
      // console.log(strByEl.sort());
      // console.log(strByEl);
      var origElem = str[i];
      // console.log(origElem);
      var elementbrk = (str[i].split('').sort());
      // console.log(elementbrk);
      var element = (elementbrk.join(''));
      // console.log(element);
        //     TempArray.push(element);
        // console.log(TempArray);
      if (!TempArray.includes(element)) {
        TempArray.push(element);
        outputArray.push(origElem);
        // console.log(TempArray);
        // console.log(outputArray);
      };
    }
        return(outputArray);
  }
  

  console.log(funWithAnagrams(['12345', '1234', 'hello', 'othello', 'hello']));
  
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
  