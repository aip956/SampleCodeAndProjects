const express = require('express');
const app = express();
const port = 3000;
const songs = require('./models/songs.js');
const myMax = songs.length - 1;
const myMin = 0;
const wives = "Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Sinatra"


// Authentication; https://stackabuse.com/handling-authentication-in-express-js/
// npm install express-handlebars
// npm install body-parser cookie-parser
const exphbs = require('express-handlebars');
const cookieParser = require('cookie-parser');
const bodyParser = require('body-parser');
app.use(express.urlencoded({extended:false}));



app.get("/",(req,res,next)=>{
    // Checking the header of the authorization
   var authheader=req.headers.authorization;
   console.log(authheader)
   if(!authheader){     
       var err=new Error("You are not authenticated")
       // Set the header for the response
       res.setHeader("WWW-Authenticate",'Basic')
       err.status=401
       return next(err)
   }
   console.log(authheader)
 
   // Decrypt the user name and the password
   var auth = new Buffer.from(authheader.split(' ')[1],
   'base64').toString().split(':');
   var user = auth[0];
   var pass = auth[1];
 
   // Checking the details
   if (user == 'admin' && pass == 'password') {
     res.send("Welcome you are authorized")
   } else {
       var err = new Error('You are not authenticated!');
       res.setHeader('WWW-Authenticate', 'Basic');
       err.status = 401;
       return next(err);
   }
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
    res.send(`
      <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e3/Frank_Sinatra_%281957_studio_portrait_close-up%29.jpg/455px-Frank_Sinatra_%281957_studio_portrait_close-up%29.jpg" >
    `);
})



app.post('/', function (req, res) {
    console.log(req.body);
    res.end();
});

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