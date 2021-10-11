const { default: axios } = require('axios');
const productURI = 'https://dast-ms-products.herokuapp.com/products/';

module.exports = class Controller {
  static async create(req, res) {
    const { name, price, qty } = req.body;

    try {
      const response = await axios({
        method: 'POST',
        url: productURI,
        data: {
          name,
          price,
          qty,
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
        url: productURI,
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
        url: productURI + id,
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
    const { name, price, qty } = req.body;

    try {
      const response = await axios({
        method: 'PUT',
        url: productURI + id,
        data: {
          name,
          price,
          qty,
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
        url: productURI + id,
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
