const jwt = require('jsonwebtoken');
const axios = require('axios');
const privateKey = process.env.PRIVATE_KEY;
const Payment = require('../models/paymentModel');
const orderURI = 'https://dast-ms-orders.herokuapp.com/orders';

module.exports = class Controller {
  static async create(req, res) {
    const { order_id, amount } = req.body;
    const status = 'paid';

    try {
      const { data } = await axios({
        method: 'PUT',
        url: `${orderURI}/${order_id}`,
        data: {
          status,
        },
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (data) {
        const newPayment = await Payment.create({
          order_id,
          status,
          amount,
        });
        res.status(201).json({ status: 'created', data: newPayment });
      }
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async read(req, res) {
    try {
      const payments = await Payment.find();
      res.status(200).json({ status: 'success', data: payments });
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async readOne(req, res) {
    const id = req.params.id;

    try {
      const payment = await Payment.findById(id);
      if (!payment) {
        throw {
          message: 'payment not found',
        };
      }
      res.status(200).json({ status: 'success', data: payment });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async update(req, res) {
    const id = req.params.id;
    const { amount, status } = req.body;

    try {
      const updatedPayment = await Payment.findByIdAndUpdate(id, { amount, status }, { new: true });
      if (!updatedPayment) {
        throw {
          message: 'payment not found',
        };
      }
      res.status(201).json({ status: 'updated', data: updatedPayment });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async destroy(req, res) {
    const id = req.params.id;

    try {
      const deletedPayment = await Payment.findByIdAndDelete(id);
      if (!deletedPayment) {
        throw {
          message: 'payment not found',
        };
      }
      res.status(200).json({ status: 'deleted', data: deletedPayment });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }
};
