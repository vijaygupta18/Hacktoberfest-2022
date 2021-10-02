const express = require('express');
const router = express.Router();
const Controller = require('../controllers/usersCotroller');

router.get('/', Controller.findAll);
router.get('/register', Controller.getRegister);
router.post('/register', Controller.postRegister);
router.get('/login', Controller.getLogin);
router.post('/login', Controller.postLogin);
router.get('/:id', Controller.profile);
router.get('/delete/:id', Controller.delete);

module.exports = router;