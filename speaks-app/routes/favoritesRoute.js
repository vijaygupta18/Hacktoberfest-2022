const express = require('express');
const router = express.Router();
const Controller = require('../controllers/favoritesController');

router.get('/', Controller.findAll);
router.get('/delete/:id', Controller.delete);

module.exports = router;