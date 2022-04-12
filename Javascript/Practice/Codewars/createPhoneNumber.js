// Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.

// Example
// createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) // => returns "(123) 456-7890"
// The returned format must be correct in order to complete this challenge.
// Don't forget the space after the closing parentheses!

function createPhoneNumber(numbers){
    let n = (numbers);
  //   let first = ((n.slice(0,3)).join(""))
  //   let second = ((n.slice(3,6)).join(""))
  //   let third = ((n.slice(6,10)).join(""))
  //   phone = `(${first}) ${second}-${third}`
      phone = `(${n[0]}${n[1]}${n[2]}) ${n[3]}${n[4]}${n[5]}-${n[6]}${n[7]}${n[8]}${n[9]}`;
    return phone;
  }