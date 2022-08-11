
function digitCount(num){
    let isItTrue = 1;
    numsCount = [0,0,0,0,0,0,0,0,0,0];
    // Create a count array for each element in num
    for (i = 0; i < num.length; i++) {
        numsCount[num[i]]++;
        // console.log(numsCount);
    } // Closes for 

    // Is each element in the string = count of the index?
    for (i = 0; i < num.length; i++) {
      if (num[i] != numsCount[i]) {
        return 0;
      };
      console.log(num[i],numsCount[i]);
      console.log(num[i] != numsCount[i]);
    } // Close for
  return isItTrue;
  } // Closes function
  
  
  
  
  console.log(digitCount("030"));
//   console.log(digitCount("1210"));
  // "1210"
  // Is index in the string that number times
  // Input: num = "030"
  // Output: false
  // Explanation:
  // num[0] = '0'. The digit 0 should occur zero times, but actually occurs twice in num.
  // num[1] = '3'. The digit 1 should occur three times, but actually occurs zero times in num.
  // num[2] = '0'. The digit 2 occurs zero times in num.
  // The indices 0 and 1 both violate the condition, so return false.
  // i is the index
  // n is the number of times
  // numsCount = [2 0 0 1 0 0 0 0 0] should be this
 // 030 => index 0, numsCount[0] ++
 //         index 1, numsCount[num[index]]++