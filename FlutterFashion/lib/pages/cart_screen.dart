import 'dart:math';

import 'package:fashion_shop/model/cart_model.dart';
import 'package:fashion_shop/model/transaction_model.dart';
import 'package:flutter/material.dart';
import 'package:lottie/lottie.dart';

class CartScreen extends StatefulWidget {
  const CartScreen({Key key}) : super(key: key);

  @override
  _CartScreenState createState() => _CartScreenState();
}

class _CartScreenState extends State<CartScreen> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade100,
      appBar: AppBar(
        elevation: 0,
        backgroundColor: Colors.transparent,
        iconTheme: IconThemeData(color: Theme.of(context).accentColor),
        title: Text(
          'My Cart',
          style: TextStyle(
              color: Theme.of(context).accentColor,
              fontWeight: FontWeight.bold),
        ),
        centerTitle: true,
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          physics: NeverScrollableScrollPhysics(),
          child: cartItemList.length < 1
              ? Center(
                  child: Column(
                    children: [
                      Container(
                        child: Lottie.asset('images/empty_cart.json'),
                      ),
                      Text('No Items'),
                    ],
                  ),
                )
              : Container(
                  width: MediaQuery.of(context).size.width,
                  height: MediaQuery.of(context).size.height,
                  child: Column(
                    children: [
                      Container(
                        width: MediaQuery.of(context).size.width,
                        alignment: Alignment.center,
                        child: Text(
                          "${cartItemList.length.toString()} Items",
                          style: TextStyle(
                              fontWeight: FontWeight.bold,
                              color: Colors.grey.shade400,
                              fontSize: 18),
                        ),
                      ),
                      SizedBox(height: 15),
                      Container(
                        height: MediaQuery.of(context).size.height / 1.5,
                        child: ListView.builder(
                          itemCount: cartItemList.length,
                          itemBuilder: (context, index) {
                            return Padding(
                              padding: const EdgeInsets.symmetric(
                                  vertical: 5.0, horizontal: 10),
                              child: Card(
                                elevation: 0.5,
                                margin: EdgeInsets.symmetric(
                                    horizontal: 10.0, vertical: 5.0),
                                shape: RoundedRectangleBorder(
                                  borderRadius: BorderRadius.circular(15),
                                ),
                                child: Container(
                                  padding: EdgeInsets.all(10.0),
                                  height: 150,
                                  child: Row(
                                    crossAxisAlignment:
                                        CrossAxisAlignment.start,
                                    children: [
                                      Container(
                                        width: 100,
                                        height: 150,
                                        padding: EdgeInsets.all(10.0),
                                        decoration: BoxDecoration(
                                          borderRadius:
                                              BorderRadius.circular(10),
                                          color: Colors.grey.shade100,
                                        ),
                                        child: Image.asset(
                                          cartItemList[index].assetImage,
                                        ),
                                      ),
                                      SizedBox(width: 15),
                                      Column(
                                        mainAxisAlignment:
                                            MainAxisAlignment.start,
                                        crossAxisAlignment:
                                            CrossAxisAlignment.start,
                                        children: [
                                          Text(
                                            cartItemList[index].title,
                                            style: TextStyle(
                                              fontWeight: FontWeight.bold,
                                              fontSize: 16,
                                            ),
                                          ),
                                          SizedBox(height: 8),
                                          Text(
                                            "Rp ${cartItemList[index].price}",
                                            style: TextStyle(
                                              color: Colors.grey,
                                              fontWeight: FontWeight.w500,
                                              fontSize: 14,
                                            ),
                                          ),
                                          SizedBox(height: 10),
                                          Row(
                                            children: [
                                              CircleAvatar(
                                                radius: 11,
                                                backgroundColor:
                                                    cartItemList[index].color,
                                              ),
                                              SizedBox(width: 8),
                                              CircleAvatar(
                                                radius: 11,
                                                backgroundColor:
                                                    Colors.grey.shade100,
                                                child: Center(
                                                  child: Text(
                                                    cartItemList[index].size,
                                                    style: TextStyle(
                                                        color: Theme.of(context)
                                                            .accentColor,
                                                        fontSize: 13),
                                                  ),
                                                ),
                                              )
                                            ],
                                          ),
                                          SizedBox(height: 5),
                                          Container(
                                            width: MediaQuery.of(context)
                                                    .size
                                                    .width /
                                                2,
                                            child: Row(
                                              mainAxisAlignment:
                                                  MainAxisAlignment
                                                      .spaceBetween,
                                              children: [
                                                Row(
                                                  children: [
                                                    IconButton(
                                                      iconSize: 14,
                                                      splashRadius: 20,
                                                      icon: Icon(Icons.remove),
                                                      onPressed: () {
                                                        setState(() {
                                                          decreaseQty(
                                                            cartItemList[index],
                                                          );
                                                        });
                                                      },
                                                    ),
                                                    SizedBox(width: 3),
                                                    Text(
                                                      cartItemList[index]
                                                          .quantity
                                                          .toString(),
                                                      style: TextStyle(
                                                        fontWeight:
                                                            FontWeight.bold,
                                                        fontSize: 16,
                                                      ),
                                                    ),
                                                    SizedBox(width: 3),
                                                    IconButton(
                                                      splashRadius: 18,
                                                      iconSize: 20,
                                                      icon: Icon(Icons.add),
                                                      onPressed: () {
                                                        setState(() {
                                                          increaseQty(
                                                              cartItemList[
                                                                  index]);
                                                        });
                                                      },
                                                    ),
                                                  ],
                                                ),
                                                IconButton(
                                                  splashRadius: 20,
                                                  iconSize: 20,
                                                  icon: Icon(
                                                    Icons.delete_outline,
                                                    color: Colors.red,
                                                  ),
                                                  onPressed: () {
                                                    setState(() {
                                                      deleteFromCart(
                                                          cartItemList[index]);
                                                    });
                                                  },
                                                ),
                                              ],
                                            ),
                                          ),
                                        ],
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                            );
                          },
                        ),
                      ),
                      SizedBox(height: 10),
                      Container(
                        width: MediaQuery.of(context).size.width,
                        padding: EdgeInsets.symmetric(horizontal: 20.0),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                Text(
                                  'Total:',
                                  style: TextStyle(
                                    fontWeight: FontWeight.w300,
                                    fontSize: 16,
                                  ),
                                ),
                                Text(
                                  getTotalPrice().toString(),
                                  style: TextStyle(
                                    fontWeight: FontWeight.w500,
                                    fontSize: 18,
                                  ),
                                ),
                              ],
                            ),
                            ElevatedButton(
                              onPressed: () {
                                if (cartItemList.isNotEmpty) {
                                  insertTransaction(generateNewTransaction());
                                  cartItemList.clear();
                                }
                                Navigator.pop(context);
                              },
                              style: ButtonStyle(
                                  shape: MaterialStateProperty.all<
                                      RoundedRectangleBorder>(
                                    RoundedRectangleBorder(
                                        borderRadius:
                                            BorderRadius.circular(15)),
                                  ),
                                  backgroundColor:
                                      MaterialStateProperty.all<Color>(
                                          Theme.of(context).accentColor)),
                              child: Container(
                                width: MediaQuery.of(context).size.width / 2.5,
                                height: 60,
                                child: Center(
                                  child: Row(
                                    mainAxisAlignment: MainAxisAlignment.center,
                                    children: [Text('Checkout Cart')],
                                  ),
                                ),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ],
                  ),
                ),
        ),
      ),
    );
  }

  TransactionModel generateNewTransaction() {
    List<CartModel> tempCartList = [];

    for (int i = 0; i < cartItemList.length; i++) {
      tempCartList.add(cartItemList[i]);
    }

    TransactionModel newTransaction = new TransactionModel(
      id: generateTransactionId(),
      amount: getTotalPrice(),
      products: tempCartList,
      dateTime: getDateTime(),
    );
    return newTransaction;
  }

  String generateTransactionId() {
    const _chars =
        'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890';
    Random _rnd = Random();

    return String.fromCharCodes(
      Iterable.generate(
        5,
        (_) => _chars.codeUnitAt(_rnd.nextInt(_chars.length)),
      ),
    );
  }

  DateTime getDateTime() {
    DateTime currentDate = DateTime.now();
    return currentDate;
  }
}
