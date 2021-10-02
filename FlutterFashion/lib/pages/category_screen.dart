import 'package:fashion_shop/pages/home_screen.dart';
import 'package:fashion_shop/widgets/category_item.dart';
import 'package:flutter/material.dart';

class CategoryScreen extends StatelessWidget {
  const CategoryScreen({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        elevation: 0,
        backgroundColor: Colors.transparent,
        iconTheme: IconThemeData(color: Theme.of(context).accentColor),
        centerTitle: true,
        title: Text(
          'Categories',
          style: TextStyle(
              color: Theme.of(context).accentColor,
              fontWeight: FontWeight.bold),
        ),
      ),
      body: SafeArea(
        child: SingleChildScrollView(
          physics: NeverScrollableScrollPhysics(),
          child: Padding(
            padding: const EdgeInsets.symmetric(
              vertical: 8.0,
              horizontal: 25.0,
            ),
            child: Container(
              height: MediaQuery.of(context).size.height,
              child: ListView(
                children: [
                  OutlinedButton(
                    style: OutlinedButton.styleFrom(
                      primary: Theme.of(context).accentColor,
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(15),
                      ),
                    ),
                    onPressed: () {
                      category = 'All';
                      Navigator.of(context).pop();
                    },
                    child: Container(
                      height: 50,
                      child: Center(
                        child: Text(
                          'Reset Category',
                        ),
                      ),
                    ),
                  ),
                  SizedBox(height: 8.0),
                  CategoryItem(
                    assetImg: 'images/women.png',
                    text: 'Women',
                    onTap: () {
                      category = 'Women';
                      Navigator.of(context).pop();
                    },
                  ),
                  CategoryItem(
                    text: 'Men',
                    assetImg: 'images/men.png',
                    onTap: () {
                      category = 'Men';
                      Navigator.of(context).pop();
                    },
                  ),
                  CategoryItem(
                    text: 'Kids',
                    assetImg: 'images/kids.png',
                    onTap: () {
                      category = 'Kids';
                      Navigator.of(context).pop();
                    },
                  ),
                  CategoryItem(
                    text: 'New Collection',
                    assetImg: 'images/new_collection.png',
                    onTap: () {
                      category = 'New Collection';
                      Navigator.of(context).pop();
                    },
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}
