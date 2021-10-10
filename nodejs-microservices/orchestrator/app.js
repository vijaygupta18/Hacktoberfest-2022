if (process.env.NODE_ENV !== 'production') require('dotenv').config();
const express = require('express');
const cors = require('cors');
const app = express();
const port = process.env.PORT || 3000;

const router = require('./routes');

app.use(cors());

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.get('/test', (req, res) => {
  res.send('OK');
});

app.use('/', router);

app.listen(port, () => {
  console.log(`listening at port: ${port}`);
});
