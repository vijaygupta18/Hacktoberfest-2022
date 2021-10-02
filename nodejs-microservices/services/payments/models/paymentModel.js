const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const paymentSchema = new Schema(
  {
    order_id: {
      type: String,
      required: true,
    },
    status: {
      type: String,
      required: true,
    },
    amount: {
      type: Number,
      required: true,
    },
  },
  { timestamps: true }
);

const Payment = mongoose.model('Payment', paymentSchema);

module.exports = Payment;
