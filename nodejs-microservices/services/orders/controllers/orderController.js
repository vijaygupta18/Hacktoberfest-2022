const jwt = require('jsonwebtoken');
const privateKey = process.env.PRIVATE_KEY;
const Order = require('../models/orderModel');

module.exports = class Controller {
  static async create(req, res) {
    const user_id = req.UserId;
    const { product_id, amount } = req.body;
    const status = 'pending';

    try {
      const newOrder = await Order.create({
        user_id,
        product_id,
        amount,
        status,
      });
      res.status(201).json({ status: 'created', data: newOrder });
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async read(req, res) {
    try {
      const orders = await Order.find();
      res.status(200).json({ status: 'success', data: orders });
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async readOne(req, res) {
    const id = req.params.id;

    try {
      const order = await Order.findById(id);
      if (!order) {
        throw {
          message: 'order not found',
        };
      }
      res.status(200).json({ status: 'success', data: order });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async update(req, res) {
    const id = req.params.id;
    const { amount, status } = req.body;

    try {
      const updatedOrder = await Order.findByIdAndUpdate(id, { amount, status }, { new: true });
      if (!updatedOrder) {
        throw {
          message: 'order not found',
        };
      }
      res.status(201).json({ status: 'updated', data: updatedOrder });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async destroy(req, res) {
    const id = req.params.id;

    try {
      const deletedOrder = await Order.findByIdAndDelete(id);
      if (!deletedOrder) {
        throw {
          message: 'order not found',
        };
      }
      res.status(200).json({ status: 'deleted', data: deletedOrder });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }
};
