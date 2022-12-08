const { Router } = require('express');
const express = require('express');
const router = express.Router();
const queries = require('../database/queries');
const Hosts = require('../database/Hosts');




// Rotes
router.get('/device/:id', (req, res) => {
    var id = req.params.id;

    queries.lastMeasure(id, (dataHumidity, dataTemperature) => {
        queries.allHosts(() => {
            // find all hosts in database and put ir order to view in index
            Hosts.findAll({raw: true, order: [
                ['alias', 'ASC']
            ]}).then(myHostsDB => {
                res.render('device', {
                    'myHosts': myHostsDB, id, dataHumidity, dataTemperature});
            });
        });
    });
});


module.exports = router;