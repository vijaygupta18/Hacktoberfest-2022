import 'package:fashion_shop/model/product_model.dart';
import 'package:flutter/material.dart';

class FavoriteButton extends StatefulWidget {
  final ProductModel product;
  bool isFavorite;

  FavoriteButton({@required this.product, @required this.isFavorite});

  @override
  _FavoriteButtonState createState() => _FavoriteButtonState();
}

class _FavoriteButtonState extends State<FavoriteButton> {
  @override
  Widget build(BuildContext context) {
    return CircleAvatar(
      backgroundColor: Colors.white.withOpacity(0.8),
      child: InkWell(
        borderRadius: BorderRadius.circular(50),
        splashColor: Theme.of(context).accentColor.withOpacity(0.5),
        onTap: () {
          setState(() {
            widget.isFavorite = !widget.isFavorite;
            if (widget.isFavorite) {
              insertFavorite(widget.product);
            } else {
              removeFromFavorite(widget.product);
            }
          });
        },
        child: Center(
          child: Icon(
              widget.isFavorite ? Icons.favorite : Icons.favorite_border,
              color: Colors.brown),
        ),
      ),
    );
  }
}
