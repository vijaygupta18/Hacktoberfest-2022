import 'package:flutter/material.dart';

class CategoryItem extends StatelessWidget {
  final String text, assetImg;
  final Function onTap;

  const CategoryItem({
    Key key,
    @required this.text,
    @required this.assetImg,
    @required this.onTap,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Card(
      margin: EdgeInsets.only(bottom: 8.0),
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
      color: Colors.grey.shade300,
      child: InkWell(
        borderRadius: BorderRadius.circular(15),
        onTap: onTap,
        child: Container(
          width: MediaQuery.of(context).size.width,
          height: 130,
          decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(15),
          ),
          child: Row(
            crossAxisAlignment: CrossAxisAlignment.center,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Container(
                margin: EdgeInsets.only(left: 32),
                child: Text(
                  text,
                  style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: 22,
                  ),
                ),
              ),
              Image.asset(
                assetImg,
              )
            ],
          ),
        ),
      ),
    );
  }
}
