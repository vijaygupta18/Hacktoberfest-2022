import 'package:carousel_slider/carousel_slider.dart';
import 'package:fashion_shop/model/cart_model.dart';
import 'package:fashion_shop/model/product_model.dart';
import 'package:fashion_shop/widgets/favorite_button.dart';
import 'package:flutter/material.dart';

class ProductDetailScreen extends StatefulWidget {
  final ProductModel product;

  ProductDetailScreen({Key key, @required this.product}) : super(key: key);

  @override
  _ProductDetailScreenState createState() => _ProductDetailScreenState();
}

class _ProductDetailScreenState extends State<ProductDetailScreen> {
  bool _isFavorite = false;
  CartModel cartItem;
  Color chosenColor;
  String chosenSize;
  int colorIndex, sizeIndex, _currentSlide = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          Stack(
            children: [
              CarouselSlider(
                options: CarouselOptions(
                    initialPage: 0,
                    enableInfiniteScroll: false,
                    viewportFraction: 1.5,
                    scrollDirection: Axis.horizontal,
                    height: MediaQuery.of(context).size.height / 2,
                    onPageChanged: (index, _) {
                      setState(() {
                        _currentSlide = index;
                      });
                    }),
                items: widget.product.networkImages.map<Widget>((imgUrl) {
                  return Container(
                    width: MediaQuery.of(context).size.width,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.only(
                        bottomRight: Radius.circular(15),
                        bottomLeft: Radius.circular(15),
                      ),
                    ),
                    child: Image.network(
                      imgUrl,
                      fit: BoxFit.cover,
                    ),
                  );
                }).toList(),
              ),
              Positioned(
                child: AppBar(
                  backgroundColor: Colors.transparent,
                  elevation: 0,
                  leading: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Container(
                      width: 50,
                      height: 50,
                      decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(50),
                          color: Colors.white.withOpacity(0.8)),
                      child: InkWell(
                        borderRadius: BorderRadius.circular(50),
                        splashColor:
                            Theme.of(context).accentColor.withOpacity(0.5),
                        onTap: () => Navigator.of(context).pop(),
                        child: Center(
                          child: Icon(Icons.arrow_back),
                        ),
                      ),
                    ),
                  ),
                  iconTheme: IconThemeData(
                    color: Theme.of(context).primaryColor,
                  ),
                  actions: [
                    Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: FavoriteButton(
                        product: widget.product,
                        isFavorite: _isFavorite,
                      ),
                    )
                  ],
                ),
              ),
              Positioned(
                bottom: 3,
                left: 10,
                right: 10,
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: widget.product.networkImages.map((imgUrl) {
                    int index = widget.product.networkImages.indexOf(imgUrl);
                    return Container(
                      width: 10.0,
                      height: 10.0,
                      margin: EdgeInsets.symmetric(
                        vertical: 10.0,
                        horizontal: 2.0,
                      ),
                      decoration: BoxDecoration(
                        shape: BoxShape.circle,
                        color: _currentSlide == index
                            ? Theme.of(context).primaryColor
                            : Theme.of(context).accentColor,
                      ),
                    );
                  }).toList(),
                ),
              ),
            ],
          ),
          Container(
            width: MediaQuery.of(context).size.width,
            height: MediaQuery.of(context).size.height / 2,
            decoration: BoxDecoration(
              color: Colors.grey.shade50,
              borderRadius: BorderRadius.only(
                topLeft: Radius.circular(15),
                topRight: Radius.circular(15),
              ),
            ),
            padding: EdgeInsets.symmetric(vertical: 12.0, horizontal: 20.0),
            child: SingleChildScrollView(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  SizedBox(height: 15),
                  Container(
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: [
                        Text(
                          widget.product.name,
                          style: TextStyle(
                            fontWeight: FontWeight.bold,
                            fontSize: 20,
                          ),
                        ),
                        Text(
                          "Rp ${widget.product.price.toString()}",
                          style: TextStyle(
                            fontWeight: FontWeight.bold,
                            fontSize: 20,
                          ),
                        ),
                      ],
                    ),
                  ),
                  SizedBox(height: 12),
                  Container(
                    child: Text(
                      widget.product.description,
                      style: TextStyle(color: Colors.grey),
                    ),
                  ),
                  SizedBox(height: 15),
                  Container(
                    child: Text(
                      'Color',
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 14,
                      ),
                    ),
                  ),
                  SizedBox(height: 5),
                  Container(
                    height: 50,
                    child: ListView.builder(
                      scrollDirection: Axis.horizontal,
                      itemCount: widget.product.productColors.length,
                      itemBuilder: (context, index) {
                        return Container(
                          margin: EdgeInsets.only(left: 5),
                          child: CircleAvatar(
                            backgroundColor:
                                widget.product.productColors[index],
                            child: InkWell(
                              onTap: () {
                                setState(() {
                                  colorIndex = index;
                                  chosenColor =
                                      widget.product.productColors[index];
                                });
                              },
                              child: Center(
                                child: colorIndex == index
                                    ? Icon(Icons.check)
                                    : Container(),
                              ),
                            ),
                          ),
                        );
                      },
                    ),
                  ),
                  SizedBox(height: 12),
                  Container(
                    child: Text(
                      'Size',
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 14,
                      ),
                    ),
                  ),
                  SizedBox(height: 5),
                  Container(
                    height: 50,
                    child: ListView.builder(
                      scrollDirection: Axis.horizontal,
                      itemCount: widget.product.productSizes.length,
                      itemBuilder: (context, index) {
                        return Container(
                          margin: EdgeInsets.only(left: 5),
                          child: CircleAvatar(
                            backgroundColor: sizeIndex == index
                                ? Theme.of(context).accentColor
                                : Colors.grey.shade100,
                            child: InkWell(
                              onTap: () {
                                setState(() {
                                  sizeIndex = index;
                                  chosenSize =
                                      widget.product.productSizes[index];
                                });
                              },
                              child: Center(
                                child: Text(
                                  widget.product.productSizes[index],
                                  style: TextStyle(
                                    color: sizeIndex == index
                                        ? Colors.grey.shade100
                                        : Theme.of(context).accentColor,
                                  ),
                                ),
                              ),
                            ),
                          ),
                        );
                      },
                    ),
                  ),
                  SizedBox(height: 40),
                  ElevatedButton(
                    onPressed: () {
                      cartItem = new CartModel(
                        id: "${widget.product.id}-$chosenSize-${chosenColor.toString()}",
                        assetImage: widget.product.assetImages,
                        title: widget.product.name,
                        quantity: 1,
                        price: widget.product.price,
                        description: widget.product.description,
                        color: chosenColor,
                        size: chosenSize,
                      );
                      setState(() {
                        if (chosenSize == null || chosenColor == null) {
                          ScaffoldMessenger.of(context).showSnackBar(
                            SnackBar(
                              content: Text('Fill all the required fields'),
                              duration: Duration(seconds: 3),
                            ),
                          );
                        } else {
                          insertCart(cartItem);
                        }
                      });
                    },
                    style: ButtonStyle(
                        shape:
                            MaterialStateProperty.all<RoundedRectangleBorder>(
                          RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(15)),
                        ),
                        backgroundColor: MaterialStateProperty.all<Color>(
                            Theme.of(context).accentColor)),
                    child: Container(
                      width: MediaQuery.of(context).size.width,
                      height: 60,
                      child: Center(
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Icon(Icons.shopping_bag_outlined),
                            SizedBox(width: 5),
                            Text('Add to cart')
                          ],
                        ),
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
