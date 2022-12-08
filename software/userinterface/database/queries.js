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
    var dataHumidity = [];
    var dataTemperature = [];
    var dataTable = [];

    const fluxQuery = `from(bucket:"${client.bucket}") |> range(start: -30d, stop: -28d)
|> filter(fn: (r) => r._measurement == "mqtt_consumer" and r.host == "8fa3519c28e3")`

    // This set avoids duplicate hosts
    client.queryApi.queryRows(fluxQuery, {
        next(row, tableMeta) {
            const o = tableMeta.toObject(row)
            if (o._field == "Humidity"){
                dataHumidity.push([o._time, o._value]);
            }
            if (o._field == "Temperature"){
                dataTemperature.push([o._time, o._value]);
            }
            console.log(
                `${o._time} ${o._measurement} in '${o.location}' ${o._field}=${o._value} ${o._field}=${o._value}`)
            
            
        },
        error(error) {
            console.error(error)
            console.log('Finished ERROR')
        },
        complete() {
            for (var i = 0; i < dataHumidity.length; i++){
                //check if umidity and temperature have the same date and time
                if (dataHumidity[i][0] == dataTemperature[i][0]){
                    dataTable.push([dataHumidity[i][0], dataHumidity[i][1], dataTemperature[i][1]]);
                }
            }
            console.log('inicio da tabela');
            console.log(dataTable);
            console.log('fim da tabela');
            callback(dataTable);
        },
    })
};

module.exports = {
    allHosts,
    lastMeasure
};