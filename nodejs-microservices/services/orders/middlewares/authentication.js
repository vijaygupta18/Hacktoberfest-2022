const jwt = require('jsonwebtoken');
const privateKey = process.env.PRIVATE_KEY;
const Order = require('../models/orderModel');

const authentication = (req, res, next) => {
  const access_token = req.headers.access_token;

  try {
    if (!access_token) {
      throw {
        name: 'TokenMissing',
        message: 'Missing access token',
      };
    }
    const decoded = jwt.verify(access_token, privateKey);
    req.UserId = decoded.id;
    next();
  } catch (error) {
    res.status(401).json({ error: error.message });
  }
};

const orderAuthorization = async (req, res, next) => {
  try {
    const orders = await Order.find({ user_id: req.UserId });
    if (!orders) {
      throw {
        name: 'NotFound',
        message: 'orders not found',
      };
    } else {
      req.orders = orders;
    }
  } catch (error) {
    console.log(error);
  }
};

module.exports = { authentication, orderAuthorization };
