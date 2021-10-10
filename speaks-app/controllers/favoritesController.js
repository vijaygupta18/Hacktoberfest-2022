const { User, Post, Favorite } = require('../models');

class Controller {
  static findAll(req, res) {
    if (req.session.login) {
      Favorite.findAll({
          include: {
            model: Post,
            include: [User],
            order: [
              ['id', 'desc']
            ]
          },
          order: [
            ['id', 'desc']
          ],
          where: {
            UserId: req.session.UserId
          }
        })
        .then(data => res.render('favorites', { data, id: req.session.UserId }))
        .catch(err => res.render('error', { id: req.session.UserId, err }));
    } else {
      res.redirect('/users/login');
    }
  }

  static delete(req, res) {
    Favorite.destroy({ where: req.params })
      .then(() => {
        if (req.query.loc == "profile") {
          res.redirect('/users/' + req.session.UserId)
        } else if (req.query.profile) {
          res.redirect('/posts?username=' + req.query.profile)
        } else if (req.query.loc == "posts") {
          res.redirect('/posts')
        } else {
          res.redirect('/favorites')
        }
      })
      .catch(err => res.render('error', { id: req.session.UserId, err }));
  }
}

module.exports = Controller;