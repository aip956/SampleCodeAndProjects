Problem:
I had a C-programming problem, to return a pointer to the first occurrence of the “needle” (substring) in the “haystack” (string). If “ll” is the needle, and “hello” is the haystack, I should return “llo”. 
Example:
needle: “ll”, haystack: “Hello”
Output should be: “llo”
What am I trying to get my code to do / logic:
Take the first element in needle, “l”, search over each element of haystack.
Is “l” in “hello”, and what is the index of the first occurrence?
If so, 
Track the starting index in haystack, haystackstart
Then take the second element in needle, “l”; is it in the next place of “hello” after the first element “l”
With each successful find of each needle element, increment a count (number of subsequent elements in substring that are found in string)
And continue to iterate each element in needle to see if the whole substring is in haystack
If count = length of the substring needle, then the whole substring needle is in the haystack string
Then return the address of the haystack element where needle starts, &haystack[haystackstart]
If there is a mismatch at any point of the substring in the string, return to the next element of the haystack and search for the first element of the substring.

My original code worked with a simple example. With haystack = “hello” and needle = “ll”, I got the correct output “llo”.
However, if haystack = “mississippi” and needle = “issip”, the needle was not found and returned NULL.

What is my code doing instead?
I love printf. It allowed me to see where my logic was not correct. I added printf in the for loop to print each needle and haystack element, the if statement (elements are equal), and the loop for subsequent elements from the needle. The printf statements indicated the needle and haystack indices and count within each loop.
This allowed me to troubleshoot. Originally, I used the same j variable for the index of the string once the first element of the substring was found in the string. 
The needle[0] element “i” is found in haystack[1],
As the subsequent elements of needle[1] - [3] (“ssi”) are sequentially found in haystack[2] - [4], the “j” variable increments; now j = 5
But when the last element, needle[4], “p”, is not found, the substring is not found in the string yet. So the search should continue back at haystack[2]. However, since I used the same “j” variable in the two loops, “j” is now 5, and the search resumes at haystack[5] instead of haystack[2]. Oops!
Since the search continues at haystack[5], it does not find the needle, and returns NULL
I then added variable jvsk (index j vs index k), initializing it to equal “j” if the first element in needle was found. And it works!
