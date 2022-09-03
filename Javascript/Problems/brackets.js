// Topic: Brackets

// Write a function that uses one string as an argument. The function returns 1if the expression is correctly bracketed, otherwise, it returns 0.

// Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' and ']'and braces '{' and '}'. Every other symbol is simply ignored.

// An opening bracket must always be closed by the good closing bracket in the correct order. A string that does not contain any bracket is considered as a correctly bracketed string.

// Example 0:
// Input: "(johndoe)"
// Output: 1

// 	Example 1:
// Input: "([)]"
// Output: 0

// Example 2:
// Input: "{[(0 + 0)(1 + 1)](3*(-1)){()}}"
// Output: 1

// Example 3:
// Input: ""
// Output: 1

// Logic:
// If an open bracket, unshift the partner closing bracket to open_bracket_array.unshift
// If encounter a close bracket, does it match the first element 0 in the array?
    // If not equal, return 0
    // Else, shift from the array
// prob need an object/ hash and a switch so that if you find a closing bracket, is it the match to the open_bracket_array[0]
// if so, shift that from the open_bracket_array
// Check if there are no more elements in the array (every bracket was matched)

function brackets(string) {
    let index = 0;
    let open_bracket_array = [];
    let output = 1;
    for (index = 0; index < string.length; index++) {
      let element = string[index];
      switch (element) {
        case "(":
          open_bracket_array.unshift(")");
          break;
        case "[":
          open_bracket_array.unshift("]");
          break;
        case "{":
          open_bracket_array.unshift("}");
          break;
      };
      if (string[index] == ")" || string[index] == "]" || string[index] == "}") {
        if (string[index] != open_bracket_array[0]) {
          return 0;
        }
        else {
          open_bracket_array.shift();
          };
      };
    };
         if (open_bracket_array.length != 0) {
         return 0;
       };  
    return output;
};
  
  
  // string = "(johndoe)"
  string = "([)]"
//   string = "{[(0 + 0)(1 + 1)](3*(-1)){()}}"
  // string = ""
  console.log(brackets(string));