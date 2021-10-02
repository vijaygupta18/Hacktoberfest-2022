import 'dart:ui';

import 'package:flutter/material.dart';

class ProductModel {
  String id;
  String name;
  String description;
  String category;
  double price;
  List<String> productSizes;
  List<Color> productColors;
  List<String> networkImages;
  String assetImages;

  ProductModel({
    @required this.id,
    @required this.name,
    @required this.description,
    @required this.category,
    @required this.price,
    @required this.assetImages,
    this.networkImages,
    @required this.productColors,
    @required this.productSizes,
  });
}

var productList = [
  ProductModel(
    id: 'CDRC-1',
    name: 'Corduroy cap',
    description:
        'A corduroy cap will perfectly complement your image. This hat is suitable for both the classic and for casual style.',
    category: 'New Collection',
    price: 340000,
    assetImages: 'images/corduroy.png',
    networkImages: [
      'https://media.glamour.com/photos/5dc5d55372672000089fd8dd/master/w_1600%2Cc_limit/GettyImages-851069504.jpg',
      'https://s2.r29static.com/bin/entry/cbb/960xbm,70/1861710/image.jpg',
      'https://blog.petitedressing.com/wp-content/uploads/2020/11/corduroy-7-571x1024.jpg',
    ],
    productColors: [
      Colors.grey.shade500,
      Colors.brown.shade100,
      Colors.brown.shade400,
      Colors.brown.shade800
    ],
    productSizes: ['S', 'M', 'L'],
  ),
  ProductModel(
    id: 'CTNS-2',
    name: 'Cotton sweatshirt',
    description:
        'A cotton sweatshirt that will perfectly fit your body. This sweatshirt is suitable for hanging out with friends etc.',
    category: 'New Collection',
    price: 210000,
    assetImages: 'images/sweatshirt.png',
    networkImages: [
      'https://static2.bigstockphoto.com/0/6/3/large1500/360128344.jpg',
      'https://tubeclothing.com/i/good/gallery_photo/photo/0005/46.jpg',
      'https://i.pinimg.com/originals/e2/24/82/e224821ebee03c2299ed64f02298fda0.jpg',
    ],
    productColors: [
      Colors.grey.shade400,
      Colors.deepOrange,
      Colors.red.shade300,
      Colors.green.shade200
    ],
    productSizes: ['S', 'M', 'L'],
  ),
  ProductModel(
    id: 'LNGT-3',
    name: 'Long trench',
    description:
        'A long trench that will perfectly your style. Most suitable for formal occasion.',
    category: 'Women',
    price: 300999,
    assetImages: 'images/long_trench.png',
    networkImages: [
      'https://d2w9m16hs9jc37.cloudfront.net/dimg/blog/2019/09/sesi__n_de_estudio_ok_331_cr2.jpg',
      'https://3.bp.blogspot.com/-sWeLP0CRXwY/W5yGGgKjiZI/AAAAAAAAIQ4/qEopJu4PM0k-9L0PMJTXZq3EqO10lex0gCLcBGAs/s1600/oversized.jpg',
      'https://lifewithjazz.com/wp-content/uploads/2020/02/IMG_3625_Facetune_23-02-2020-01-32-47-819x1024.jpg',
    ],
    productColors: [
      Colors.black54,
      Colors.brown.shade200,
      Colors.lightBlue.shade100,
      Colors.green.shade200
    ],
    productSizes: ['S', 'M', 'L'],
  ),
  ProductModel(
    id: 'CSLH-4',
    name: 'Casual hoodie',
    description:
        'A hoodie that will spark your day. Use it when hanging out and your friend will be shocked.',
    category: 'Men',
    price: 100500,
    assetImages: 'images/hoodie.png',
    networkImages: [
      'https://colorlib.com/wp/wp-content/uploads/sites/2/mockup-featuring-a-woman-wearing-a-customizable-full-zip-hoodie.jpg',
      'https://c8.alamy.com/comp/2BXD1GE/male-model-wear-stylish-white-hoodie-sweater-isolated-on-grey-background-front-and-back-view-copy-space-mock-up-template-for-print-design-2BXD1GE.jpg',
      'https://previews.123rf.com/images/geldinn/geldinn1807/geldinn180700003/105383980-black-jumper-hoodie-jacket-mock-up-front-and-back-view-isolated-male-model-wear-baseball-jumper-jack.jpg',
    ],
    productColors: [
      Colors.blue.shade800,
      Colors.blueGrey,
      Colors.yellow.shade300,
      Colors.deepOrangeAccent
    ],
    productSizes: ['S', 'M', 'L'],
  ),
  ProductModel(
    id: 'TRTLS-5',
    name: 'Turtleneck sweater',
    description:
        'A sweater that will warm your body. Most suitable to wear in winter season.',
    category: 'New Collection',
    price: 350000,
    assetImages: 'images/sweater.png',
    networkImages: [
      'https://st3.depositphotos.com/3647147/18933/i/1600/depositphotos_189338194-stock-photo-beautiful-sexy-woman-long-brunette.jpg',
      'https://previews.123rf.com/images/ilyabukowski/ilyabukowski2004/ilyabukowski200400107/144152220-blank-sweatshirt-mock-up-isolated-female-wear-plain-hoodie-mockup-plain-hoody-design-presentation-cl.jpg',
      'https://i.pinimg.com/736x/ce/f9/54/cef954bfba4126da52eab2ea0983bc74.jpg',
    ],
    productColors: [
      Colors.black54,
      Colors.brown.shade200,
      Colors.cyan.shade100,
      Colors.pinkAccent.shade100
    ],
    productSizes: ['S', 'M', 'L'],
  ),
];

var favoriteProductList = [];
var searchResult = [];
var categoryResult = [];

void insertFavorite(ProductModel product) {
  if (!favoriteProductList.contains(product)) {
    favoriteProductList.add(product);
  }
}

void removeFromFavorite(ProductModel product) {
  if (favoriteProductList.contains(product)) {
    favoriteProductList.remove(product);
  }
}

List<ProductModel> searchProduct(String query) {
  return productList.where((data) => data.name.contains(query)).toList();
}

List<ProductModel> categoryList(String category) {
  return productList.where((data) => data.category.contains(category)).toList();
}
