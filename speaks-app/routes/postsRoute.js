const express = require('express');
const router = express.Router();
const Controller = require('../controllers/postsController');

router.get('/', Controller.findAll);
router.get('/add', Controller.getAdd);
router.post('/add', Controller.postAdd);
router.get('/edit/:id', Controller.getEdit);
router.post('/edit/:id', Controller.postEdit);
router.get('/delete/:id', Controller.delete);
router.get('/favorite/:id', Controller.fav);

module.exports = router;