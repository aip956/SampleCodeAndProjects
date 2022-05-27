/* Given a matrix, if any of the cells in the matrix is 0, set all the elements in its row and column to 0.

1 1 1        1 0 1
1 0 1   =>   0 0 0
1 1 1        1 0 1
*/

// Create matrix copy, output
// Create an array to hold indices of 0 locations
// For each row and column, if the element is 0,
//  push the element indices to the array of zeros
// For each sub-array in zero array (location of zero),
//  set i_0 and j_0 as the indices / row and column of the zero
// For each row in the matrix,
//  If the column is j_0 (column of 0), change that element to 0
//  If the row is = i_0 (row of a 0), change the row to 0's


  
  function rowColumnZero(matrix) {
    var output = matrix;
    // console.log("18Matrix",matrix);
    // console.log("19Output",output);
    var zeroArr = [];
    var i_0, j_0, i, j;
  
    for (i = 0; i < 3; i++) { // rows
      for (j = 0; j < 3; j++) { // columns 
        console.log("24ij", i,j);
        if (matrix[i][j] === 0) {
          zeroArr.push([i,j]);
          console.log("26 i,j", i, j);
          console.log("29 0Arr:", zeroArr)
            console.log("27", output);
        } // closes if
      } // closes for j
      console.log("33 0Arr:", zeroArr)
    } // closes for loop

      for (m = 0; m < zeroArr.length; m++) {
            console.log("37 m arr ele", m);
            i_0 = zeroArr[m][0];
            j_0 = zeroArr[m][1];
            console.log("40 i0, j0", i_0, j_0);

        for (p = 0; p < matrix.length; p++) {
            console.log("43length", matrix.length);
            console.log("44arr len",(matrix[p]).length);
            console.log("45 p row", p)
          

            for (q = 0; q < (matrix[p]).length; q++) {
                console.log("46 q col", q);
                console.log("48", output[p]);
                console.log("49 j_0", j_0);
                if (q === j_0) {
                    output[p][q] = 0;
                    console.log("51pq", p, q);
                    console.log("53", output[p]);
                    console.log("55q", q);
                } //closes if q
            } // closes for q
            if (p == i_0) {
                output[p] = [0,0,0];
                console.log("61 p, output", p, output[p]);

            } //closes if p
        } // closes for p
      } // closes for m loop


    return output;
  }; //closes function
  

//   console.log(rowColumnZero([[1,1,1], [1,0,1], [1,1,1]]));
//   [ [ 1, 0, 1 ], [ 0, 0, 0 ], [ 1, 0, 1 ] ]

//   console.log(rowColumnZero([[0,1,2], [3,4,5], [1,2,3]]));
//   [ [ 0, 0, 0 ], [ 0, 4, 5 ], [ 0, 2, 3 ] ]

// console.log(rowColumnZero([[0,1,0], [3,4,5], [1,2,3]]));
// [ [ 0, 0, 0 ], [ 0, 4, 0 ], [ 0, 2, 0 ] ]

//   console.log(rowColumnZero([[0,1,0], [3,0,5], [1,2,3]]));
  // [ [ 0, 0, 0 ], [ 0, 0, 0 ], [ 0, 0, 0 ] ]

  
  // loop through each sub-array, is 0 an element 
  // if there is a 0, take i[j]
  // the resulting sub-array becomes 0
  // the other array's jth element becomes 0

