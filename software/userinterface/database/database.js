// InfluxDB

const { InfluxDB } = require('@influxdata/influxdb-client')

// You can generate an API token from the "API Tokens Tab" in the UI
const token = 'WCHiXnonzowflQRsO7QM'
const org = 'espertamente'
const bucket = 'bee'
const url = 'https://influxdb.bee.espertamente.com.br'

const client = new InfluxDB({ url: url, token: token })

const queryApi = client.getQueryApi(org)


// SQLite3
// For ubuntu, before install dependences or if you received a error in 'npm install sqlite3' do this:
// 'sudo apt install node-sqlite' now you can do 'npm install sqlite3'

const Sequelize = require('sequelize')
const sequelize = new Sequelize({
    dialect: 'sqlite',
    storage: './database/config.sqlite'
})

// Exports

module.exports = {
    client,
    sequelize,
    queryApi,
    bucket
};