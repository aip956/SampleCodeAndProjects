// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]


// function moveZeroes(nums) {
//     for (i = 0; i < nums.length; i++) {
//       if (nums[i] === 0) {
//         nums.splice(i, 1);
//         nums.push(0);
//       }
//     }
//     return nums;
//     }
// console.log(moveZeroes([1,0,2,0,3,0,4,0]));


// Without using JS methods
function moveZeroes(nums) {
    var zeroArr = [];
    var nonZero = [];
    var zi = 0;
    var ni = 0;
    var newArr = [];
    var newi = 0;
  for (i = 0; i < nums.length; i++) {
      // console.log("i:"+i);
      if (nums[i] === 0) {
        // console.log("zi: "+zi);
        zeroArr[zi] = 0;
        zi++;
        // console.log("zeroArr:"+zeroArr);
    } // closes if
    else {
       // console.log("ni: "+ni);
       nonZero[ni] = nums[i];
        ni++;
        // console.log("nonZero:"+nonZero);
    } // closes else
  } // closes for loop
  for (newi = 0; newi < nonZero.length; newi++) {
    newArr[newi] = nonZero[newi];
    // console.log("newArr")
    // console.log(newArr);
    // console.log("newi:"+newi);
  } // closes for loop
  for (zi = 0; zi < zeroArr.length; zi++) {
    // console.log("97 newi:"+newi);
    newArr[newi] = zeroArr[zi];
    newi++;
    // console.log("newArr")
    // console.log(newArr); 
  } // closes for loop
      return newArr;
  }  // closes function
  
// console.log(moveZeroes([1,0,2,0,3,0,4,0]));
// console.log(moveZeroes([0,1,0,3,12]));