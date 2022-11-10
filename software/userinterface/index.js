(async () => {
    const database = require('./database/database');
    const Hosts = require('./database/Hosts');

    try {
        const hosts = await database.sequelize.sync();
        console.log(hosts);
        console.log('ok');
    } catch (error) {
        console.log(error);
        console.log('erro');
    }
})();

const express = require('express');
const app = express();
const client = require('./database/database');
const queries = require('./database/queries');

// use ejs how view engine
app.set('view engine', 'ejs');

// use express to static files
app.use(express.static('public'));


// Routes
app.get('/', (req, res) => {
    

    res.render('index')
    

    
});



// Server
app.listen(8080, () => {
    console.log('App starting');
});