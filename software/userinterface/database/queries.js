const client = require('./database');


const query = `from(bucket: "${client.bucket}") 
                |> range(start: -365d)
                |> distinct(column: "host")`

function allhosts() {

    // This set avoids duplicate hosts
    const mySet = new Set()
    var myhost;

    client.queryApi.queryRows(query, {
        next(row, tableMeta) {
            const o = tableMeta.toObject(row)
            // console.log(`${o.host}`)

            // add host in set
            myhost = o.host
            mySet.add(myhost)
        },
        error(error) {
            console.error(error)
            console.log('Finished ERROR')
        },
        complete() {
            // console.log(mySet.size)
            // console.log('Finished SUCCESS')
            return mySet;

        },
        

    })



};


module.exports = {
    allhosts
};