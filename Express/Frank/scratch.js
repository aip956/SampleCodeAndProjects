const songs = [
    {
      "ID": 1,
      "Song": "Ac-cent-tchu-ate the Positive"
    },
    {
      "ID": 2,
      "Song": "Accidents Will Happen"
    },
    {
      "ID": 3,
      "Song": "Adeste Fideles"
    },
    {
      "ID": 4,
      "Song": "Ad-Lib Blues"
    },
    {
      "ID": 5,
      "Song": "An Affair to Remember (Our Love Affair)"
    }
]

function randomRange(myMin, myMax) {
  myMax = songs.length - 1;
  myMin = 0;
  // console.log(myMax);
  i = Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
  console.log(i);
  return(songs[i]["Song"])

  // Only change code below this line
  // return Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
  // Only change code above this line
 }
 
// console.log(songs[0]["Song"])
// console.log(songs[0]["ID"])
console.log(randomRange());
