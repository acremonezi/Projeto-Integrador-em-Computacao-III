const express = require('express');
const app = express();
const client = require('./database/database');

// use ejs how view engine
app.set('view engine', 'ejs');

// use express to static files
app.use(express.static('public'));


// Routes
app.get('/', (req, res) => {
    res.render('index');
});


// Server
app.listen(8080, () => {
    console.log('App starting');
});