const router = require('express').Router();
const { create, read, readOne, update, destroy } = require('../controllers/productController');
const authentication = require('../middlewares/authentication');

router.use(authentication);

router.post('/', create);
router.get('/', read);
router.get('/:id', readOne);
router.put('/:id', update);
router.delete('/:id', destroy);

module.exports = router;
