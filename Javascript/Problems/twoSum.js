// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

var twoSum = function(nums, target) {
    var twoSum = [];
    var i = 0;
    var j = 1;
    var length = nums.length;
    
  for (i = 0; i < length - 1; i++) {
      for (j = 1; j < length; j++) {
          if (nums[i] + nums[j] == target && i != j) {
              twoSum.push(i, j)
              return twoSum;
          } // closes if
      } // closes for j
    } // closes for i
  }