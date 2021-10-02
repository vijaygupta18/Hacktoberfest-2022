const jwt = require('jsonwebtoken');
const privateKey = process.env.PRIVATE_KEY;
const User = require('../models/userModel');
const { cryptPassword, checkPassword } = require('../helpers/bcrypt');

module.exports = class Controller {
  static async register(req, res) {
    const newName = req.body.name;
    const newEmail = req.body.email;
    let newPassword = req.body.password;
    if (newPassword) {
      newPassword = cryptPassword(req.body.password);
    }

    try {
      const userIsExist = await User.findOne({ email: newEmail });
      if (userIsExist) {
        throw {
          name: 'RegisterError',
          message: `Email ${userIsExist.email} is already registered!`,
        };
      } else {
        try {
          const newUser = await User.create({
            name: newName,
            email: newEmail,
            password: newPassword,
          });
          res.status(201).json({ status: 'created', email: newUser.email });
        } catch (error) {
          res.status(500).json({ error: error.message });
        }
      }
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async login(req, res) {
    const emailLogin = req.body.email.toLowerCase();
    const passwordLogin = req.body.password;

    try {
      if (!emailLogin) {
        throw {
          name: 'FieldRequired',
          message: 'Email field is required',
        };
      } else if (!passwordLogin) {
        throw {
          name: 'FieldRequired',
          message: 'Password field is required',
        };
      }

      const user = await User.findOne({ email: emailLogin });
      if (user) {
        const passwordDb = user.password;
        const passwordMatch = checkPassword(passwordLogin, passwordDb);
        if (passwordMatch) {
          const userID = user._id;
          const access_token = jwt.sign({ id: userID }, privateKey);
          res.status(200).json({ success: 'loged in', id: userID, access_token });
        } else {
          throw {
            name: 'LoginError',
            message: 'Wrong Password!',
          };
        }
      } else {
        throw {
          name: 'LoginError',
          message: 'Email in not registered!',
        };
      }
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }
};
