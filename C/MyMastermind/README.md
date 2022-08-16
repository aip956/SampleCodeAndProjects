Welcome to My Mastermind
Task
TODO - This is an implementation of the Mastermind number guessing game. There are two players, player 1 and player 2.
There are 8 pieces of different colors, and a secret code composed of 4 distinct pieces.
Typically, the player 2 has 10 tries to guess the right pieces and sequence. After each guess, the Player 2 will be told the number of correctly placed pieces, and misplaced pieces.
In this implementation, the Player 1 can enter a secret, of any length (not limited to 4). Player 1 can also enter the maximum number of tries the player 2 will have.

Description
TODO - How have you solved the problem?
Determine if Player 1 has entered a secret and/or maximum number of tries. If so, determine if those inputs are valid (numbers). If no secret was entered, generate a random number secret of length 4. 

Player 2 will be told how many numbers to enter (and numbers 0 -7). If Player 2 enters an incorrect number of elements, or incorrect type, they will be prompted to re-enter (and will stay in the same round).

If Player 2 guesses the correct sequence within the maximum number of tries, they will be told they won. Otherwise, they will be told the secret.

Solution
Player 1 Input:
To determine if Player 1 entered a secret or max tries, I searched for flags "-c" (secret) and "-t" (tries). If a c-flag is found, then validate the secret consists of numbers (0 -7 for secret), and generate a character string from it. If there's a t-flag, convert the input to a number. 
    *(Functions isFlagC, isFlagT, checkSecret, makeSecretArr, makeMaxTries)

If there's no c-flag, generate a secret code of random numbers, length of 4, and convert to a character string.
    *(Function ranSecret)

Player 2 Input:
Program reads the input. To support EOF (ctrl + d), continue of the read return is not 0.
Validate the input length is correct and valid (numbers). I used goto so that if these criteria did not pass, the player stays in the round and re-enters their guess.

For each element/digit in the guess, check against the secret to determine if it's a correctly placed match (right number and place). 
    *(Function compareForX)

To check the mismatched places (right number and wrong place), generate an array for the secret and guess, indicating the number of elements by index. For example, a secret of 0232 = [1, 0, 2, 1, 0, 0, 0, 0]. For each digit, compare the secret and guess arrays; where they are both > 0 is a match, and the minimum is the number of matches. 
    *(Functions fill_array, compareForZ)



Installation
TODO - How to install your project? npm install? make? make re?
No installation needed. Program run from terminal command line.

Usage
TODO - How does it work?
Player one types program name, optionally can add secret (-c) and/or max tries (-t):
./my_mastermind -c "0123" -t "4"
./my_mastermind -c "0123"
./my_mastermind -t "4"


The Core Team
Made at Qwasar Silicon Valley Qwasar Silicon Valley Logo