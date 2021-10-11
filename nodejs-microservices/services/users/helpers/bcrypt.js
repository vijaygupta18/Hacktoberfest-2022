const bcrypt = require('bcryptjs');

function cryptPassword(password) {
  return bcrypt.hashSync(password, bcrypt.genSaltSync(10));
}

function checkPassword(password, db_password) {
  return bcrypt.compareSync(password, db_password);
}

module.exports = {
  cryptPassword,
  checkPassword,
};
