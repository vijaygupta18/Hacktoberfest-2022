import 'package:flutter/material.dart';

import 'cart_model.dart';

class TransactionModel {
  final String id;
  final double amount;
  List<CartModel> products;
  final DateTime dateTime;

  TransactionModel({
    @required this.id,
    @required this.amount,
    @required this.products,
    @required this.dateTime,
  });
}

List<TransactionModel> transactionList = [];

void insertTransaction(TransactionModel transactionModel) {
  transactionList.add(transactionModel);
}

void removeTransaction(TransactionModel transactionModel) {
  transactionList.remove(transactionModel);
}
