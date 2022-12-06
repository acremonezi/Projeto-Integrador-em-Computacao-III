const client = require('./database');
const Hosts = require('./Hosts');



const query = `from(bucket: "${client.bucket}") 
                |> range(start: -365d)
                |> distinct(column: "host")`



function allHosts(callback) {

    // This set avoids duplicate hosts
    const myHosts = new Set()

    client.queryApi.queryRows(query, {
        next(row, tableMeta) {
            const o = tableMeta.toObject(row)
            myHosts.add(o.host)
        },
        error(error) {
            console.error(error)
            console.log('Finished ERROR')
        },
        complete() {
            myHosts.forEach((value) => {
                Hosts.findOrCreate({
                    where: {host: value},
                }).then(([hostTemp, created]) => {
                    console.log(created);
                });
            });
            console.log('finish');
            callback(myHosts);
        },
    })
};



function lastMeasure(id, callback) {
    var id = id;
    
    var listHumidity = [];
    var dateHumidity = [];
    var listTemperature = [];
    var dateTemperature = [];

    const fluxQuery = `from(bucket:"${client.bucket}") |> range(start: -30d, stop: -20d)
|> filter(fn: (r) => r._measurement == "mqtt_consumer" and r.host == "8fa3519c28e3")`

    // This set avoids duplicate hosts
    client.queryApi.queryRows(fluxQuery, {
        next(row, tableMeta) {
            const o = tableMeta.toObject(row)
            if (o._field == "Humidity"){
                listHumidity.push(o._value);
                dateHumidity.push(o._time);
            }
            if (o._field == "Temperature"){
                listTemperature.push(o._value);
                dateTemperature.push(o._time);
            }
            console.log(
                `${o._time} ${o._measurement} in '${o.location}' ${o._field}=${o._value} ${o._field}=${o._value}`)
        },
        error(error) {
            console.error(error)
            console.log('Finished ERROR')
        },
        complete() {
            console.log('finish');
            
            callback(dateHumidity, listHumidity, dateTemperature, listTemperature);
        },
    })
};

module.exports = {
    allHosts,
    lastMeasure
};