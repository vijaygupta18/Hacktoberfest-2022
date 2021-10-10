const { User, Post, Favorite } = require('../models');
const { compareHash } = require('../helpers/bcrypt');
const { Op } = require("sequelize");

class Controller {
  static findAll(req, res) {
    const search = req.query.username || "";
    if (req.session.login) {
      User.findAll({
          where: {
            username: {
              [Op.iLike]: `%${search}%`
            }
          },
          order: ['id']
        })
        .then(data => res.render('users', { data, id: req.session.UserId }))
        .catch(err => res.render('error', { id: req.session.UserId, err }));
    } else {
      res.redirect('/users/login');
    }
  }

  static profile(req, res) {
    if (req.session.login) {
      User.findByPk(req.session.UserId, {
          include: [Post, Favorite],
          order: [
            ['id', 'desc']
          ]
        })
        .then(data => {
          res.render('profile', { data, id: req.session.UserId, user: null, favorites: data.Favorites })
        })
        .catch(err => res.render('error', { id: req.session.UserId, err }));
    } else {
      res.redirect('/users/login');
    }
  }

  static getRegister(req, res) {
    const error = req.query.err || null
    res.render('register-form', { error, id: req.session.UserId });
  }

  static postRegister(req, res) {
    User.create(req.body)
      .then(() => {
        const success = 'Your account has been successfully registered, you can login now!';
        res.redirect('/users/login?success=' + success);
      })
      .catch(err => {
        let msg;
        if (err.fields.username) msg = `Account with username: "${err.fields.username}" already registered!`;
        else if (err.fields.email) msg = `Account with email: "${err.fields.email}" already registered!`;
        else msg = err.errors[0].message;
        res.redirect('/users/register/?err=' + msg);
      });
  }

  static getLogin(req, res) {
    if (req.session.login) {
      res.redirect('/posts');
    } else {
      const error = req.query.err || null;
      const success = req.query.success || null;
      const uname = req.query.uname || '';
      res.render('login-form', { error, success, id: req.session.UserId, uname });
    }
  }

  static postLogin(req, res) {
    User.findOne({
        where: {
          username: req.body.username,
        }
      })
      .then((user) => {
        if (user) {
          if (compareHash(req.body.password, user.password)) {
            req.session.login = true;
            req.session.username = user.username;
            req.session.UserId = user.id;
            res.redirect('/posts');
          } else {
            throw new Error('Wrong password!');
          }
        } else {
          throw new Error('Username is not registered!');
        }
      })
      .catch((err) => {
        res.redirect('/users/login/?err=' + err.message + '&uname=' + req.body.username);
      });
  }

  static delete(req, res) {
    User.destroy({ where: req.params })
      .then(() => res.redirect('/posts'))
      .catch(err => res.render('error', { id: req.session.UserId, err }));
  }
}

module.exports = Controller;