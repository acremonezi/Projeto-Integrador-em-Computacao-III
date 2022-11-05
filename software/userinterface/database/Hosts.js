const Sequelize = require('sequelize')
const database = require('./database')

const Host = database.sequelize.define('host', {
    host: {
        type: Sequelize.TEXT,
        allowNull: false
    },
    alias: {
        type: Sequelize.TEXT,
        allowNull: true
    }
});

module.exports = Host;