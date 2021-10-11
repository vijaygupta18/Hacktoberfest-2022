const { default: axios } = require('axios');
const orderURI = 'https://dast-ms-orders.herokuapp.com/orders/';

module.exports = class Controller {
  static async create(req, res) {
    const { product_id, amount } = req.body;

    try {
      const response = await axios({
        method: 'POST',
        url: orderURI,
        data: {
          product_id,
          amount,
        },
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (response.data) {
        res.status(201).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }

  static async read(req, res) {
    try {
      const response = await axios({
        method: 'GET',
        url: orderURI,
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (response.data) {
        res.status(200).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }

  static async readOne(req, res) {
    const id = req.params.id;

    try {
      const response = await axios({
        method: 'GET',
        url: orderURI + id,
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (response.data) {
        res.status(200).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }

  static async update(req, res) {
    const id = req.params.id;
    const { amount, status } = req.body;

    try {
      const response = await axios({
        method: 'PUT',
        url: orderURI + id,
        data: {
          amount,
          status,
        },
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (response.data) {
        res.status(200).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }

  static async destroy(req, res) {
    const id = req.params.id;

    try {
      const response = await axios({
        method: 'DELETE',
        url: orderURI + id,
        headers: {
          access_token: req.headers.access_token,
        },
      });
      if (response.data) {
        res.status(200).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }
};
