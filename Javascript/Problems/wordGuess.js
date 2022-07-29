// Generate/pick random word from list
// Generate a blank display of "_" for each letter
// Prompt user for a letter "guess"
// If the guessed letter is in the word, replace the blank in
// the displayed word with the letter
// If the guess is not in the word, give an error
// Indicate the remaining tries, and unfilled spaces
// If there all spaces are filled, you win!
// If you use the seven tries without solving, print the word
// Does not catch a duplicated guessed letter
// Does not run in VS Code; for interactive version, 
// https://replit.com/@AntheaIp/WordGuess#index.js



function WordGuess() {
    wordPool = ["apple", "water", "friend", "pizza", "jumbo"];
    var ranWord = wordPool[Math.floor(Math.random()*wordPool.length)];
    // console.log(ranWord);
    ranWordLen = ranWord.length;
    dispWordArr = [];
    unfilled = ranWordLen;
  
    // Generate blank display word
    for (i = 0; i < ranWordLen; i++) {
      dispWordArr.push("_");
      var dispWord = dispWordArr.join("");
    } // Closes for
  
    // For 7 tries
    for (tries = 1; tries  < 8; tries ++) {
      if (unfilled != 0) { // if there are unfilled spaces
        // Prompt to enter a letter
        let guess = prompt("Please enter a letter, Try# "+tries);
          guess = guess.toLowerCase()
            // Is the guess in the ranWord?
          isGuessInWord = false;
          // is the guess in the word?
          for (index = 0; index < ranWordLen; index++) {
            if (guess == ranWord[index])	{
              unfilled --;
              isGuessInWord = true;
              dispWordArr[index] = guess;
              dispWord = dispWordArr.join("");
                } // Closes if guess is in ranWord
            } // Closes for 
          if (isGuessInWord == false) {
            console.log("Not in word");
            } // Closes if
          
          console.log("Unfilled:", unfilled);
          console.log(dispWord);
          triesRemain = 7 - tries;
          console.log("Tries remaining: ", triesRemain);
        } // Closes for each try
      
        if (unfilled == 0) {
                  return("You've won!");
        } // If all filled, winner
      } // Closes if unfilled
    return("Too many guesses; answer is: "+ranWord);
  } // Closes function
  
  console.log(WordGuess());
  