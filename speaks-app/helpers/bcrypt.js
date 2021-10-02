const bcrypt = require('bcryptjs')

function hash(password) {
  return bcrypt.hashSync(password, bcrypt.genSaltSync(3))
}

function compareHash(password, db_password) {
  return bcrypt.compareSync(password, db_password)
}

module.exports = {
  hash,
  compareHash
}