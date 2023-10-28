const express = require('express');

const app = express();
const PORT = 3000;


app.get("/", function (req, res) {
    request(
        "https://api.sampleapis.com/coffee/hot",
        function(error, response,body) {
            const obj = JSON.parse(body)
        }
    )


})


app.listen(PORT, (error) => {
  if (!error) {
    console.log("Server is running, and App is listening on port " + PORT);
  } else {
    console.log("Error occurred, server can't start", error);
  }
});