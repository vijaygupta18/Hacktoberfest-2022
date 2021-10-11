const jwt = require('jsonwebtoken');
const privateKey = process.env.PRIVATE_KEY;
const Product = require('../models/productModel');

module.exports = class Controller {
  static async create(req, res) {
    const { name, price, qty } = req.body;

    try {
      const newProduct = await Product.create({
        name,
        price,
        qty,
      });
      res.status(201).json({ status: 'created', data: newProduct });
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async read(req, res) {
    try {
      const products = await Product.find();
      res.status(200).json({ status: 'success', data: products });
    } catch (error) {
      res.status(500).json({ error: error.message });
    }
  }

  static async readOne(req, res) {
    const id = req.params.id;

    try {
      const product = await Product.findById(id);
      if (!product) {
        throw {
          message: 'product not found',
        };
      }
      res.status(200).json({ status: 'success', data: product });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async update(req, res) {
    const id = req.params.id;
    const { name, price, qty } = req.body;

    try {
      const updatedProduct = await Product.findByIdAndUpdate(id, { name, price, qty }, { new: true });
      if (!updatedProduct) {
        throw {
          message: 'product not found',
        };
      }
      res.status(201).json({ status: 'updated', data: updatedProduct });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }

  static async destroy(req, res) {
    const id = req.params.id;

    try {
      const deletedProduct = await Product.findByIdAndDelete(id);
      if (!deletedProduct) {
        throw {
          message: 'product not found',
        };
      }
      res.status(200).json({ status: 'deleted', data: deletedProduct });
    } catch (error) {
      res.status(404).json({ error: error.message });
    }
  }
};
