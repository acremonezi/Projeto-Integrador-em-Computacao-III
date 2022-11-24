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
    sequelize
};