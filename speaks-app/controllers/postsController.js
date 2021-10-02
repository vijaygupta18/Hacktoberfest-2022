require('dotenv').config();
const { User, Post, Favorite } = require('../models');
const path = require('path');
const multer = require('multer');
const cloudinary = require('cloudinary');

const storage = multer.diskStorage({
  destination: './public/images/',
  filename: function (req, file, cb) {
    const postId = req.app.locals.postId;
    cb(null, file.fieldname + '-' + postId + path.extname(file.originalname));
  },
});

const upload = multer({
  storage: storage,
}).single('image');

cloudinary.config({
  cloud_name: process.env.cloud_name,
  api_key: process.env.api_key,
  api_secret: process.env.api_secret,
});

class Controller {
  static findAll(req, res) {
    if (req.session.login) {
      if (req.query.username) {
        let user;
        User.findOne({
          where: {
            username: req.query.username,
          },
          include: {
            model: Post,
            order: [['id', 'desc']],
          },
        })
          .then((data) => {
            user = data;
            return User.findByPk(req.session.UserId, { include: [Favorite] });
          })
          .then((fav) => {
            res.render('profile', { data: user, id: req.session.UserId, user: req.query.username, favorites: fav.Favorites });
          })
          .catch((err) => res.render('error', { id: req.session.UserId, err }));
      } else {
        Post.findAll({
          include: [User, Favorite],
          order: [['id', 'desc']],
        })
          .then((data) => {
            req.app.locals.postId = data[0].id + 1;
            res.render('posts', { data: data || null, id: req.session.UserId });
          })
          .catch((err) => res.render('error', { id: req.session.UserId, err }));
      }
    } else {
      res.redirect('/users/login');
    }
  }

  static getAdd(req, res) {
    res.render('post-form', { user: {}, id: req.session.UserId });
  }

  static postAdd(req, res) {
    //* Upload image to server (public folder using multer)
    upload(req, res, (err) => {
      if (err) {
        res.render('error', { id: req.session.UserId, err });
      } else {
        // * Upload local/server image to cloudinary
        const postId = req.app.locals.postId;
        delete req.app.locals.id;
        console.log(req.file.path);
        cloudinary.uploader.upload(
          req.file.path,
          function (result) {
            console.log(result);

            Post.create({
              title: req.body.title,
              description: req.body.description,
              img_url: `${result.secure_url}`,
              UserId: req.session.UserId,
            })
              .then(() => res.redirect('/posts'))
              .catch((err) => res.render('error', { id: req.session.UserId, err }));
          },
          { public_id: postId }
        );
      }
    });
  }

  static getEdit(req, res) {
    Post.findOne({ where: req.params })
      .then((user) => {
        res.render('post-form', { user, id: req.session.UserId });
      })
      .catch((err) => res.render('error', { id: req.session.UserId, err }));
  }

  static postEdit(req, res) {
    Post.update(req.body, { where: req.params })
      .then(() => {
        if (req.query.loc == 'profile') {
          res.redirect('/users/' + req.session.UserId);
        } else {
          res.redirect('/posts');
        }
      })
      .catch((err) => res.render('error', { id: req.session.UserId, err }));
  }

  static delete(req, res) {
    let deleted;
    Post.findByPk(req.params.id)
      .then((data) => {
        deleted = data;
        return Post.destroy({ where: req.params });
      })
      .then(() => {
        if (req.query.loc == 'profile') {
          res.redirect('/users/' + req.session.UserId);
        } else {
          res.redirect('/posts');
        }
      })
      .catch((err) => res.render('error', { id: req.session.UserId, err }));
  }

  static fav(req, res) {
    Favorite.create({
      UserId: req.session.UserId,
      PostId: req.params.id,
    })
      .then(() => {
        if (req.query.loc == 'profile') {
          res.redirect('/users/' + req.session.UserId);
        } else if (req.query.profile) {
          res.redirect('/posts?username=' + req.query.profile);
        } else {
          res.redirect('/posts');
        }
      })
      .catch((err) => res.render('error', { id: req.session.UserId, err }));
  }
}

module.exports = Controller;
