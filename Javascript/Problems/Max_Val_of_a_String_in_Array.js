/*
The value of an alphanumeric string can be defined as:
The numeric representation of the string in base 10, if it comprises of digits only.
The length of the string, otherwise.
Given an array strs of alphanumeric strings, return the maximum value of any string in strs.
Example 1:
Input: strs = ["alic3","bob","3","4","00000"]
Output: 5
Explanation: 
- "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
- "bob" consists only of letters, so its value is also its length, i.e. 3.
- "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
- "4" also consists only of digits, so its value is 4.
- "00000" consists only of digits, so its value is 0.
Hence, the maximum value is 5, of "alic3".

Example 2:
Input: strs = ["1","01","001","0001"]
Output: 1
Explanation: 
Each string in the array has value 1. Hence, we return 1.

LOGIC:
For each string in array,
Determine if number (isNaN())
Yes => find length
    If length > max, max = length
No => ParseInt to num
    If val > max, max = val

Return max
*/



var maximumValue = function(strs) {
    let i = 0;
  let len = 0;
  let max_val = 0;
//   console.log(isNaN("alic3"));
  for (i = 0; i < strs.length; i++) {
    if (isNaN(strs[i])) {
      len = strs[i].length;
    //   console.log(len);
      if (len > max_val) {
      max_val = len;
    //   console.log("MaxVal: ", max_val);
        }
    }
    else {
      int_val = parseInt(strs[i]);
      // console.log("ParsInt: ", int_val);
      if (int_val > max_val) {
        max_val = int_val;
      } 
    }
  }
  return max_val;
};