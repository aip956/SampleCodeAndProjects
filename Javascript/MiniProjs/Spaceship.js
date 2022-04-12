// This simulator creates a virtual “space” and keeps track of the basic movements and direction of a given ship. Your job is to keep track of where the ship is and it’s orientation relative to its starting point.

// Your ship simulator must take in a string of letters that represent a planned flight path for a given rocket ship.

// In a ship’s flight path there are only 3 valid options for movement; R for turning right, L for turning left and A for advancing.

// If, for example, you receive “RRALAA” as your flight path, you should interpret it as the following:
// Turn right, turn right, advance, turn left, advance, advance
// Once given this initial flight path, your program must return the x,y coordinates of a ship’s final destination as well as it’s orientation relative to the starting point.

// Orientation is represented as left, right, up or down.

// Space is infinite, so the x,y coordinates you return could be placed on a seemingly infinite grid and can be negative or positive values.

// So let's say an upward facing rocket ship leaves its starting point of 0,0 and is given the flight path of “RRALAA”, it’s final location will be 2,-1 and it will be facing right.

// Your Job
// You must create a function that takes in a flight path of a rocket ship as a string of letters and returns the following format:
// "{x: X, y: Y, direction: 'DIRECTION'}"
// X,Y represent the ending coordinates of your ship and direction represents its final direction.

// LOGIC
// direction, xCoord, yCoord var
// starting xCoord = 0; yCoord = 0; dir = up;
//first loop proc direction; if r, if north, bearing is east; else if a
// string of directions
// if element is left: if current direction is 
// up => left
// left => down
// down => right
// right => up

// if element is right: if current direction:
// up => right
// right => down
// down => left
// left => up

// if element is a
// up => yCoord --
// right => xCoord ++
// down => yCoord ++
// left => xCoord --


function my_spaceship(input) {
    input = input.toUpperCase();
    // console.log(input);
    var dir = "up";
    var xCoord = 0;
    var yCoord = 0;
    for (let i = 0; i < input.length; i++) {
        // console.log(input[i]);
        // console.log(i);
        if (input[i] == "L") {
            if (dir == "up") {
                dir = "left";
            }
            else if (dir == "left") {
                dir = "down";
            }
            else if (dir == "down") {
                dir = "right";
            }
            else if (dir == "right") {
                dir = "up";
            }
        }
        else if (input[i] == "R") {
            if (dir == "up") {
                dir = "right";
            }
            else if (dir == "right") {
                dir = "down";
            }
            else if (dir == "down") {
                dir = "left";
            }
            else if (dir == "left") {
                dir = "up";
            }
        }
        else if (input[i] == "A") {
            if (dir == "up") {
                yCoord--;
            }
            else if (dir == "right") {
                xCoord++;
            }
            else if (dir == "down") {
                yCoord++;
            }
            else if (dir == "left") {
                xCoord--;
            }
        }
        // console.log(dir);
        // console.log(xCoord, yCoord)
    }
    return `{x: ${xCoord}, y: ${yCoord}, direction: '${dir}'}`
}


// console.log(my_spaceship("RAALALL"));
// console.log(my_spaceship("AAAA"));
// console.log(my_spaceship("RAARA"));
// console.log(my_spaceship(""));
// console.log(my_spaceship("raalall"));