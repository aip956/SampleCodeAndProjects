const express = require('express')
const app = express()
const port = 3000
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
    },
    {
      "ID": 6,
      "Song": "After You've Gone"
    },
    {
      "ID": 7,
      "Song": "Ain't She Sweet"
    },
    {
      "ID": 8,
      "Song": "Ain't Cha Ever Comin' Back?"
    },
    {
      "ID": 9,
      "Song": "Air For English Horn"
    },
    {
      "ID": 10,
      "Song": "Alice Blue Gown"
    },
    {
      "ID": 11,
      "Song": "All Alone"
    },
    {
      "ID": 12,
      "Song": "All By Myself"
    },
    {
      "ID": 13,
      "Song": "All I Do Is Dream of You"
    },
    {
      "ID": 14,
      "Song": "All I Need is the Girl"
    },
    {
      "ID": 15,
      "Song": "All My Tomorrows"
    },
    {
      "ID": 16,
      "Song": "All of Me"
    },
    {
      "ID": 17,
      "Song": "All of You"
    },
    {
      "ID": 18,
      "Song": "All or Nothing at All"
    },
    {
      "ID": 19,
      "Song": "All the Things You Are"
    },
    {
      "ID": 20,
      "Song": "All the Way"
    },
    {
      "ID": 21,
      "Song": "All the Way Home"
    },
    {
      "ID": 22,
      "Song": "All This and Heaven Too"
    },
    {
      "ID": 23,
      "Song": "All Through the Day"
    },
    {
      "ID": 24,
      "Song": "Almost Like Being in Love"
    },
    {
      "ID": 25,
      "Song": "Always"
    }
]
const myMax = songs.length - 1;
const myMin = 0;



app.get('/', function(req, res) {

    var randSong = getSong(myMin, myMax) 
      res.send("Here's a random song: " + randSong);
})


function getSong(myMin, myMax) {
    var i = Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
    console.log(i);
    return(songs[i]["Song"])
}

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
//   console.log(i);
  console.log(myMax);
  console.log(myMin);
  console.log(songs);
})