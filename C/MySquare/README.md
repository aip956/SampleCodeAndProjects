# Welcome to My Square
***

## Task
Create a program which displays a beautiful square.
my_square(5,3) should display:

$>./a.out 5 3
o---o
|   |
o---o
$>


First and last rows have o's for first and last column
First and last rows have -'s for inside columns
Inside rows: Outside columns have | , and inside columns are spaces

## Description
I created a struct for a square
My main function:
 - checks if there are three inputs (program, rows, columns)
 - if not, it ends
 - if rows or columns are 0, ends
 - the square is built by printing each row, defined by function "my_Square"
my_Square function
 - checks if the malloc does not error
 - for each row, the struct square's array will be a row
 - malloc based on number of columns
 - for first and last rows:
  - first and last columns are 'o'
  - other (inside) columns are '-'
 - for other rows   
  - first and last columns are '|'
  - other (inside) columns are ' '
 - end each row with null '\0' 

## Installation
Change directory to ex00
type: cd ex00

## Usage
Run by typing name of program, number of columns, number of rows
type: ./my_square 5 3 
result:
o---o
|   |
o---o

### The Core Team
Anthea Ip

<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
