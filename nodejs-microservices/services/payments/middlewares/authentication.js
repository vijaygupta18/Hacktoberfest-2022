const jwt = require('jsonwebtoken');
const privateKey = process.env.PRIVATE_KEY;

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

module.exports = authentication;
