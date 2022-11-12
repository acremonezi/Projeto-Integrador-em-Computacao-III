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
            callback(myHosts);
        },
    })
};


module.exports = {
    allHosts
};