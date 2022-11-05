const {InfluxDB} = require('@influxdata/influxdb-client')

// You can generate an API token from the "API Tokens Tab" in the UI
const token = 'WCHiXnonzowflQRsO7QM'
const org = 'espertamente'
const bucket = 'bee'
const url = 'https://influxdb.bee.espertamente.com.br'

const client = new InfluxDB({url: url, token: token})

module.exports = {
    client
};