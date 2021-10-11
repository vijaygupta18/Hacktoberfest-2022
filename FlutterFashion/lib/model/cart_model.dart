import 'package:flutter/material.dart';

class CartModel {
  final String id;
  final String assetImage;
  final String title;
  final String description;
  final Color color;
  final String size;
  int quantity;
  final double price;

  CartModel({
    @required this.id,
    @required this.assetImage,
    @required this.title,
    @required this.description,
    @required this.color,
    @required this.size,
    @required this.quantity,
    @required this.price,
  });
}

List<CartModel> cartItemList = [];

void insertCart(CartModel product) {
  if (checkCart(product)) {
  } else {
    cartItemList.add(product);
  }
}

bool checkCart(CartModel product) {
  for (int i = 0; i < cartItemList.length; i++) {
    if (cartItemList[i].id == product.id) {
      cartItemList[i].quantity++;
      return true;
    }
  }
  return false;
}

void increaseQty(CartModel product) {
  product.quantity += 1;
}

void decreaseQty(CartModel product) {
  if (product.quantity > 1) {
    product.quantity -= 1;
  }
}

void deleteFromCart(CartModel product) {
  cartItemList.remove(product);
}

double getTotalPrice() {
  double total = 0;

  for (int i = 0; i < cartItemList.length; i++) {
    total = total + (cartItemList[i].price * cartItemList[i].quantity);
  }

  return total;
}
