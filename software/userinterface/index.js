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
const Hosts = require('./database/Hosts');
const Host = require('./database/Hosts');
const bodyParser = require('body-parser');
// use ejs how view engine
app.set('view engine', 'ejs');

// use express to static files
app.use(express.static('public'));

//use express with body-parser
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());


// Routes

// main page
app.get('/', (req, res) => {
    // queries.allHosts update the list of hosts
    queries.allHosts(() => {
        // find all hosts in database and put ir order to view in index
        Hosts.findAll({raw: true, order: [
            ['alias', 'ASC']
        ]}).then(myHostsDB => {
            res.render('index', {'myHosts': myHostsDB});
        });
    });
});


// open host config, to set alias
app.get('/config/:id', (req, res) => {
    var id = req.params.id;
    
    Hosts.findOne({
        where: {id: id}
    }).then(oneHost => {
        if (oneHost != undefined){
            res.render('config', {'oneHost': oneHost});
        }else{
            res.redirect('/');
        }
    });
});

// set alias for individual host
app.post('/saveconfig', (req, res) => {
    var hostAlias = req.body.hostAlias;
    var hostId = req.body.hostId;

    console.log('chegou');
    console.log(hostAlias);
    console.log(hostId);

    Hosts.update({alias: hostAlias}, {
        where: {
            id: hostId
        }
    });
    res.redirect('/');
    
});

// Server
app.listen(8080, () => {
    console.log('App starting');
});