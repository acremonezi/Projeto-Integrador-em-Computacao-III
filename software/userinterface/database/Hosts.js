const Sequelize = require('sequelize')
const database = require('./database')

const Host = database.sequelize.define('Host', {
    host: {
        type: Sequelize.STRING,
        allowNull: false,
    },
    alias: {
        type: Sequelize.TEXT,
        allowNull: true
    }
});

Host.sync({force: false,}).then(() => {
    console.log('table Host created');
});

module.exports = Host;