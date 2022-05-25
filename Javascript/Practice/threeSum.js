// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

var threeSum = function(nums) {
    var i = 0;
    var j = 0;
    var k = 0;
    var array = [];
    var arrOfSorts = [];
    var outputArr = [];
    for (i = 0; i < nums.length-2; i++) {
        for (j = i+1; j < nums.length-1 && i != j; j++) {
            for (k = j+1; k < nums.length && i != j != k; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    array = [nums[i], nums[j], nums[k]];
                    console.log("ijk",i,j,k)
                    sortedArr = array.sort();
                    console.log("Array", array);
                    console.log("Sorted", sortedArr);
                    // console.log("ArrOfSorts", arrOfSorts)
                    // console.log(!(arrOfSorts.includes(sortedArr)))
                    // console.log((arrOfSorts.includes(sortedArr)))
                   console.log("25 arrSort incl sorted", array.every(element => {arrOfSorts.includes(element); }));
                   console.log("26 arrSort not incl sorted", !array.every(element => {arrOfSorts.includes(element); }));
                    if (!array.every(element => {arrOfSorts.includes(element)})) {
                        arrOfSorts.push(sortedArr);
                        console.log("26 arrOfSorts", arrOfSorts);
                        outputArr.push(array);
                        console.log("28 outp Arr", outputArr);
                        }
                }; // closes if
            }; // closes for k
        }; // closes for j
    }; // closes for i
    return outputArr;
};

console.log(threeSum([-1,0,1,2,-1,-4]));

