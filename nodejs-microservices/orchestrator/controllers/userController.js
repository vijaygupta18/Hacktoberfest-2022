const { default: axios } = require('axios');
const userURI = 'https://dast-ms-users.herokuapp.com/users';

module.exports = class Controller {
  static async register(req, res) {
    const { name, email, password } = req.body;

    try {
      const response = await axios.post(userURI + '/register', { name, email, password });
      if (response.data) {
        res.status(201).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }

  static async login(req, res) {
    const email = req.body.email.toLowerCase();
    const password = req.body.password;

    try {
      const response = await axios.post(userURI + '/login', { email, password });
      if (response.data) {
        res.status(201).json(response.data);
      }
    } catch (error) {
      res.status(500).json({ error: error.response.data.error || error.message });
    }
  }
};
