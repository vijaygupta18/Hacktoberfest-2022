import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:google_fonts/google_fonts.dart';


void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFFF5F5F5),
      appBar: AppBar(
        backgroundColor: Colors.transparent,
        elevation: 0,
        leading: IconButton(
          onPressed: () {},
          icon: const Icon(Icons.arrow_back_ios),
          color:const Color(0xff291C5F),
        ),
      ),
      
      body: Column(
        children: [
          Padding(
            padding: const EdgeInsets.only(top: 30),
            child: Stack(
              children: [
                Center(
                  child: Padding(
                    padding:
                        const EdgeInsets.only(left: 10, right: 10, top: 60),
                    child: Container(
                      width: 380,
                      height: 150,
                      decoration: const BoxDecoration(
                        borderRadius: BorderRadius.all(
                          Radius.circular(10),
                        ),
                        
                        gradient: LinearGradient(
                          begin: Alignment.topLeft,
                          end: Alignment.bottomRight,
                          colors: [
                            Color(0xFF6a9ed8),
                            Color(0xFF796bb8)
                          ]
                        ),
                        boxShadow: [
                          BoxShadow(color: Color(0xFF796bb8),
                          blurRadius: 6,
                          offset: Offset(3, 2))
                        ]
                      ),
                      child: Padding(
                        padding: const EdgeInsets.only(
                            left: 200, top: 20, bottom: 40, right: 10),
                        child: Column(
                          children: [
                            Row(
                              children:  [
                                Text(
                                  "Alen Kuriakose",
                                  style: GoogleFonts.merriweather(textStyle: const TextStyle(fontSize: 20, fontWeight: FontWeight.w800, color:Colors.white,),) ),
                                
                              ],
                            ),
                            const Spacer(
                              flex: 1,
                            ),
                            Row(
                              children:  [
                                Text(
                                  "UI/UX Designer",
                                  style: GoogleFonts.ubuntu(textStyle: const TextStyle(fontSize: 13,fontWeight: FontWeight.w600,color: Colors.white)),
                                ), 
                              ],
                            ),
                            const Spacer(
                              flex: 1,
                            ),
                            Row(
                              children:  [
                                Text(
                                  "Full Stack Developer",
                                  style: GoogleFonts.ubuntu(textStyle: const TextStyle(fontSize: 13,fontWeight: FontWeight.w600,color: Colors.white)),
                                ),
                              ],
                            ),
                            const Spacer(
                              flex: 2,
                            )
                          ],
                        ),
                      ),
                    ),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.only(left: 35),
                  child: Container(
                    width: 140,
                    height: 190,
                    decoration: const BoxDecoration(
                      borderRadius: BorderRadius.all(
                        Radius.circular(10),
                      ),
                      color: Colors.green,
                      image: DecorationImage(
                          image: AssetImage('assets/profile.jpg'),
                          fit: BoxFit.fill),
                          boxShadow: [
                            BoxShadow(
                              color: Colors.black54,
                              blurRadius: 8,
                              offset: Offset(2, 2),
                            )
                          ],
                    ),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.only(left: 217, top: 160),
                  child: Container(
                    height: 35,
                    width: 80,
                    decoration: const BoxDecoration(
                      borderRadius: BorderRadius.all(
                        Radius.circular(5),
                      ),
                      
                      color: Color(0xFF6a9ed8),
                    ),
                    child:  Center(
                      child: Text(
                        'Hire me',
                        style: GoogleFonts.ubuntu(textStyle: const TextStyle(fontSize: 14,fontWeight: FontWeight.w800,color: Colors.white,letterSpacing: .5),
                        ),
                      ),
                    ),
                  ),
                ),
                const Spacer(
                  flex: 1,
                ),
              ],
            ),
          ),
          Stack(
            children: [
              Padding(
                padding: const EdgeInsets.only(top: 40),
                child: Center(
                  child: Container(
                    height: 350,
                    width: 380,
                    decoration: const BoxDecoration(
                      borderRadius: BorderRadius.all(
                        Radius.circular(10),
                      ),
                      color: Colors.white,
                      boxShadow: [
                            BoxShadow(
                              color: Colors.black12,
                              blurRadius: 14,
                              offset: Offset(0, 4),
                            )
                          ],
                    ),
                  ),
                ),
              ),
              SizedBox(
                height: 420,
                width: double.infinity,
                
                child: Padding(
                  padding: const EdgeInsets.all(20),
                  child: Padding(
                    padding: const EdgeInsets.all(20),
                    child: Column(
                      children: [
                        const Spacer(
                          flex: 3,
                        ),
                        Row(
                          children:  [
                            Text(
                              'About me',
                              style: GoogleFonts.ubuntu(textStyle: const TextStyle(fontSize: 15,fontWeight: FontWeight.w600,color: Colors.black45)),
                            ),
                          ],
                        ),
                        const Spacer(),
                        Row(
                          children:  [
                            Text(
                              'Lorem ipsum dolor sit amet,consectetur addgf \nscing elit. Nam aliquet ligula vitae djlit tefdf,\nvel dignissim leo scelerisque. Praesen mollis \nquam maximus dui scelerisque, eget rutrum\ndolor ullamcorper.', 
                              overflow: TextOverflow.ellipsis,
                              maxLines: 5,
                              style: GoogleFonts.lato(textStyle: const TextStyle(fontSize: 15,fontWeight: FontWeight.w600,color: Color(0xff291C5F),letterSpacing: 0.5),),
                            ),
                          ],
                        ),
                        const Spacer(
                          flex: 2,
                        ),
                        Row(
                          children:  [
                            Text(
                              'Phone',
                              style: GoogleFonts.ubuntu(textStyle: TextStyle(fontSize: 15,fontWeight: FontWeight.w600,color: Colors.black45),),
                              ),
                          ],
                        ),
                        const Spacer(),
                        Row(
                          children:  [
                            Text(
                              '+1234567890',
                              style: GoogleFonts.lato(textStyle: const TextStyle(fontSize: 15,fontWeight: FontWeight.w800,color: Color(0xff291C5F),letterSpacing: 0.5),),
                            ),
                          ],
                        ),
                        const Spacer(
                          flex: 2,
                        ),
                        Row(
                          children:  [
                            Text(
                              'Address',
                              style: GoogleFonts.ubuntu(textStyle: TextStyle(fontSize: 15,fontWeight: FontWeight.w600,color: Colors.black45)),
                            ),
                          ],
                        ),
                        const Spacer(),
                        Row(
                          children:  [
                            Text(
                              'House No 14, Asgard',
                              style: GoogleFonts.lato(textStyle: const TextStyle(fontSize: 15,fontWeight: FontWeight.w800,color: Color(0xff291C5F),letterSpacing: 0.5),),
                            ),
                          ],
                        ),
                        const Spacer(
                          flex: 3,
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ],
          ),
        ],
      ),
      bottomNavigationBar: BottomNavigationBar(
        elevation:0,
        backgroundColor:Colors.white,
        unselectedItemColor: Colors.black26,
        selectedItemColor: const Color(0xFF5C6BC0),
        type: BottomNavigationBarType.fixed,
        currentIndex: 0,
        items: const <BottomNavigationBarItem>[
          BottomNavigationBarItem(
            icon: FaIcon(
              FontAwesomeIcons.userAlt,
            ),
            label: 'Profile',
          ),
          BottomNavigationBarItem(
            icon: FaIcon(
              FontAwesomeIcons.audible,
            ),
            label: 'Feed',
          ),
        ],
      ),
    );
  }
}
