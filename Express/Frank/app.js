const express = require('express')
const app = express()
const port = 3000
const songs = require('./models/songs.js')
const myMax = songs.length - 1;
const myMin = 0;
const wives = "Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Sinatra"
const picture = "https://en.wikipedia.org/wiki/File:Frank_Sinatra_(1957_studio_portrait_close-up).jpg"


app.get('/', function(req, res) {

    var randSong = getSong(myMin, myMax) 
      res.send("Here's a random song: " + randSong);
})

app.get('/birth_date', function(req, res) {
      res.send("Frank's birthday is December 12, 1915");
})

app.get('/birth_city', function(req, res) {
    res.send("Frank was born in Hoboken, New Jersey");
})

app.get('/wives', function(req, res) {
    res.send(wives);
})

app.get('/picture', function(req, res) {
    res.send(`
            <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e3/Frank_Sinatra_%281957_studio_portrait_close-up%29.jpg/455px-Frank_Sinatra_%281957_studio_portrait_close-up%29.jpg" >
    `);
})



function getSong(myMin, myMax) {
    var i = Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
    console.log(i);
    return(songs[i]["Song"])
}

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
//   console.log(i);
//   console.log(myMax);
//   console.log(myMin);
//   console.log(songs[i]);
})