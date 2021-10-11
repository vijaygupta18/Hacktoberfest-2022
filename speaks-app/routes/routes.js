const express = require('express');
const router = express.Router();
const usersRoute = require('./usersRoute');
const postsRoute = require('./postsRoute');
const favoritesRoute = require('./favoritesRoute');

router.get('/', (req, res) => res.redirect('/users/login'));
router.get('/about', (req, res) => res.render('about', { id: req.session.UserId }));
router.get('/logout', (req, res) => {
  req.session.destroy((err) => {
    if (err) res.send(err)
    res.redirect('/users/login')
  });
  delete req.app.locals.session;
});

router.use('/users', usersRoute);
router.use('/posts', postsRoute);
router.use('/favorites', favoritesRoute);

module.exports = router;