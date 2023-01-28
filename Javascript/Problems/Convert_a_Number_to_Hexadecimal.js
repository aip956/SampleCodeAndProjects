/**
 * @param {number} num
 * @return {string}
 */
 var toHex = function(num) {
    hex_output = [];
  
    if (num == 0) {
      return "0"};
  
    if (num < 0) {
      num += 2 ** 32;
    }

    result = num;
    while (result > 0) {
      remainder = result % 16;
      result = Math.trunc(result/16);
      hex_string = "0123456789abcdef"
      hex_output.unshift(hex_string[remainder]);
  } 
  output = hex_output.join('');
  return output;
  };