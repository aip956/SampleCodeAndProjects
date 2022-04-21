const express = require('express');
const app = express();
const port = 8080;
const songs = require('./models/songs.js');
const myMax = songs.length - 1;
const myMin = 0;
const wives = "Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Sinatra"
const basicAuth = require('express-basic-auth')



app.get('/public', function(req, res) {
    res.send("Everybody can see this page");
})

app.get('/protected', basicAuth(
    { users: { 'admin': 'admin' }, 
    unauthorizedResponse: "Not authorized"
}), function(req, res) {
    res.send("Welcome, authenticated client");
})


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
    res.redirect('https://upload.wikimedia.org/wikipedia/commons/a/af/Frank_Sinatra_%2757.jpg');
})



function getSong(myMin, myMax) {
    var i = Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
    console.log(i);
    return(songs[i]["Song"])
}

app.listen(port, function(err) {
    if (err) console.log(err);
  console.log(`Example app listening on port ${port}`)
//   console.log(i);
//   console.log(myMax);
//   console.log(myMin);
//   console.log(songs[i]);
});