if (process.env.NODE_ENV !== 'production') require('dotenv').config();
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const app = express();
const port = process.env.PORT || 3001;
const router = require('./routes/userRoute');

app.use(cors());

const dbURI = process.env.MONGODB_URI;
mongoose
  .connect(dbURI, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(() => {
    app.listen(port, () => {
      console.log(`listening at port: ${port}`);
    });
  })
  .catch((err) => console.log(err));

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.get('/', (req, res) => {
  res.send('anggidast users service connected');
});
app.use('/users', router);
