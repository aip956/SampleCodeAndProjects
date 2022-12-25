# Welcome to My Mastermind
***

## Task
This is an implementation of the Mastermind number guessing game. There are two players, 
player 1 and player 2.</br>
There are 8 pieces of different colors, and a secret code composed of 4 distinct pieces.</br>
Typically, the player 2 has 10 tries to guess the right pieces and sequence. After each guess,
 the Player 2 will be told the number of correctly placed pieces, and misplaced pieces.
In this implementation, the Player 1 can enter a secret, of any length (not limited to 4). 
Player 1 can also enter the maximum number of tries the player 2 will have.</br>


## Description
Determine if Player 1 has entered a secret and/or maximum number of tries. 
If so, determine if those inputs are valid (numbers). If no secret was entered, 
generate a random number secret of length 4. </br>

Player 2 will be told how many numbers to enter (and numbers 0 -7). 
If Player 2 enters an incorrect number of elements, or incorrect type, 
they will be prompted to re-enter (and will stay in the same round).</br>

If Player 2 guesses the correct sequence within the maximum number of tries, 
they will be told they won. Otherwise, they will be told the secret.</br>

Solution
Player 1 Input:
To determine if Player 1 entered a secret or max tries, I searched for 
flags "-c" (secret) and "-t" (tries). If a c-flag is found, then validate 
the secret consists of numbers (0 -7 for secret), and generate a character 
string from it. If there's a t-flag, convert the input to a number. </br>
    *(Functions isFlagC, isFlagT, checkSecret, makeSecretArr, makeMaxTries)</br>

If there's no c-flag, generate a secret code of random numbers, length of 4, 
and convert to a character string.</br>
    *(Function ranSecret)</br>

Player 2 Input:
Program reads the input. To support EOF (ctrl + d), continue of the read 
return is not 0.</br>
Validate the input length is correct and valid (numbers). I used goto so 
that if these criteria did not pass, the player stays in the round and re-enters their guess.

For each element/digit in the guess, check against the secret to determine if it's a correctly placed match (right number and place). 
    *(Function compareForX)

To check the mismatched places (right number and wrong place), generate an array for the secret and guess, indicating the number of elements by index. For example, a secret of 0232 = [1, 0, 2, 1, 0, 0, 0, 0]. For each digit, compare the secret and guess arrays; where they are both > 0 is a match, and the minimum is the number of matches. 
    *(Functions fill_array, compareForZ)

Here's my basic logic and structure:
Main: 
* take in the input, 
* create a game state (determine the secret and tries)
* play the game with the game state

Create a game state:
* take in the ac and av, the input 
* (eg, ./my_mastermind "e", 
* * there are 2 terms; ac = 2
* * the input array, av = [./my_mastermind, -e])
* determine if there is a -e, -m, or -h flag
* * If there's a -e, the secret will consist of non-repeating numbers 0 - 3, 10 guesses
* * If there's a -m, the secret will consist of potentially duplicate numbers 0 - 7, 10 guesses
* * If there's a -h, the secret will consist of potentially duplicate numbers 0 - 9, 8 guesses
* Secret is generated with API 



Play the game:
* take in the game state (of secret and number of tries)
* Play a round
* * read in the input guess
* * have the EOF section
* * check the guess is valid (all number chars and right length)
* * compare the secret to the guess
* * * determine number of well-placed matches
* * * determine mis-placed matches
* * Determine if the player won
* * Output the X and Y (well and mis-placed)
* * Player can type "h" for a hint
* * * Indicate which numbers are right place and wrong place
* Determine if the player has more guesses left 



## Installation
Program run from terminal command line.
<pre><code>Navigate to the directory to clone the repository
Type: git clone https://github.com/aip956/MyMM.git (to clone)
Type: cd/MyMM to change into the project directory
Type: ./my_mastermind -c "0123" -t "4" (to run the program)
</code></pre>


## Usage
Player one types program name, optionally can add secret (-c) and/or max tries (-t):
    <pre><code>./my_mastermind -c "0123" -t "4"</br>
    ./my_mastermind -c "0123"</br>
    ./my_mastermind -t "4"</br></pre></code>
