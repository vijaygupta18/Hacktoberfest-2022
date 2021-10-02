import 'dart:async';

import 'package:fashion_shop/model/product_model.dart';
import 'package:fashion_shop/model/transaction_model.dart';
import 'package:fashion_shop/pages/cart_screen.dart';
import 'package:fashion_shop/pages/transaction_screen.dart';
import 'package:flutter/material.dart';

import '../model/cart_model.dart';
import '../widgets/product_grid.dart';
import 'category_screen.dart';

String category = 'All';

class HomeScreen extends StatefulWidget {
  const HomeScreen({Key key}) : super(key: key);

  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  bool showFavoriteOnly = false;
  bool searchMode = false;

  FutureOr onGoBack(dynamic value) {
    setState(() {
      if (category != 'All') categoryResult = categoryList(category);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade50,
      body: SafeArea(
        child: SingleChildScrollView(
          physics: NeverScrollableScrollPhysics(),
          child: Padding(
            padding: const EdgeInsets.symmetric(
              vertical: 10.0,
              horizontal: 25.0,
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    CircleAvatar(
                      backgroundColor: Colors.grey.shade200,
                      child: Icon(
                        Icons.shopping_basket_outlined,
                        color: Colors.black,
                      ),
                    ),
                    Row(
                      children: [
                        Stack(
                          alignment: Alignment.center,
                          children: [
                            InkWell(
                              onTap: () => Navigator.of(context)
                                  .push(
                                    MaterialPageRoute(
                                      builder: (context) => TransactionScreen(),
                                    ),
                                  )
                                  .then(onGoBack),
                              borderRadius: BorderRadius.circular(10),
                              child: Container(
                                width: 50,
                                height: 50,
                                child: Icon(
                                  Icons.history_outlined,
                                  size: 24,
                                ),
                              ),
                            ),
                            Positioned(
                              right: 6,
                              top: 9,
                              child: Container(
                                padding: EdgeInsets.all(2.0),
                                decoration: BoxDecoration(
                                  borderRadius: BorderRadius.circular(10.0),
                                  color: Theme.of(context).primaryColor,
                                ),
                                constraints: BoxConstraints(
                                  minWidth: 16,
                                  minHeight: 16,
                                ),
                                child: Text(
                                  transactionList.length.toString(),
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      fontSize: 10, color: Colors.white),
                                ),
                              ),
                            )
                          ],
                        ),
                        Stack(
                          alignment: Alignment.center,
                          children: [
                            InkWell(
                              onTap: () => Navigator.of(context)
                                  .push(
                                    MaterialPageRoute(
                                      builder: (context) => CartScreen(),
                                    ),
                                  )
                                  .then(onGoBack),
                              borderRadius: BorderRadius.circular(10),
                              child: Container(
                                width: 50,
                                height: 50,
                                child: Icon(
                                  Icons.shopping_bag_outlined,
                                  size: 24,
                                ),
                              ),
                            ),
                            Positioned(
                              right: 6,
                              top: 9,
                              child: Container(
                                padding: EdgeInsets.all(2.0),
                                decoration: BoxDecoration(
                                  borderRadius: BorderRadius.circular(10.0),
                                  color: Theme.of(context).primaryColor,
                                ),
                                constraints: BoxConstraints(
                                  minWidth: 16,
                                  minHeight: 16,
                                ),
                                child: Text(
                                  cartItemList.length.toString(),
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      fontSize: 10, color: Colors.white),
                                ),
                              ),
                            )
                          ],
                        ),
                      ],
                    ),
                  ],
                ),
                SizedBox(height: 15),
                Container(
                  child: Text(
                    'The most popular\nclothes today',
                    style: TextStyle(fontWeight: FontWeight.bold, fontSize: 28),
                  ),
                ),
                SizedBox(height: 15),
                Container(
                  padding: EdgeInsets.all(2.0),
                  decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(10.0),
                      color: Colors.grey.withOpacity(0.1)),
                  child: Center(
                    child: TextField(
                      autofocus: false,
                      onChanged: (value) {
                        if (value.isNotEmpty) {
                          setState(() {
                            searchMode = true;
                            searchResult = searchProduct(value);
                          });
                        } else {
                          setState(() {
                            searchMode = false;
                          });
                        }
                      },
                      decoration: InputDecoration(
                        border: InputBorder.none,
                        prefixIcon: Icon(
                          Icons.search,
                          color: Colors.grey,
                        ),
                        hintText: 'Search...',
                        hintStyle: TextStyle(color: Colors.grey),
                      ),
                    ),
                  ),
                ),
                SizedBox(height: 5),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    if (category != 'All')
                      Text(
                        showFavoriteOnly
                            ? 'My Favorite'
                            : 'Category: $category',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    if (category == 'All')
                      Text(
                        showFavoriteOnly ? 'My Favorite' : 'All Fashion',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    PopupMenuButton(
                      onSelected: (value) {
                        if (value == '1') {
                          setState(() {
                            showFavoriteOnly = true;
                          });
                        } else {
                          setState(() {
                            showFavoriteOnly = false;
                          });
                        }
                      },
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(15),
                      ),
                      tooltip: 'Show filter',
                      child: Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Row(
                          children: [
                            Icon(
                              Icons.filter_list,
                            ),
                            SizedBox(width: 5),
                            Text(
                              'Filter',
                            )
                          ],
                        ),
                      ),
                      itemBuilder: (_) => [
                        PopupMenuItem(
                          child: Text('Only Favorites'),
                          value: '1',
                        ),
                        PopupMenuItem(
                          child: Text('Show All'),
                          value: '2',
                        ),
                      ],
                    ),
                  ],
                ),
                ProductGrid(
                  category: category,
                  favoriteMode: showFavoriteOnly,
                  callback: onGoBack,
                  searchMode: searchMode,
                ),
              ],
            ),
          ),
        ),
      ),
      floatingActionButton: ElevatedButton(
        onPressed: () => Navigator.of(context)
            .push(
              MaterialPageRoute(builder: (context) => CategoryScreen()),
            )
            .then(onGoBack),
        style: ButtonStyle(
          backgroundColor: MaterialStateProperty.all<Color>(
            Theme.of(context).accentColor,
          ),
          shape: MaterialStateProperty.all<RoundedRectangleBorder>(
            RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(50.0),
            ),
          ),
        ),
        child: Container(
          width: 180,
          height: 50,
          child: Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Icon(Icons.category_outlined),
              SizedBox(width: 5),
              Text('View All Categories'),
            ],
          ),
        ),
      ),
    );
  }
}
