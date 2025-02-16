import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        backgroundColor: Colors.black,
        appBar: AppBar(
          backgroundColor: Colors.black,
          foregroundColor: Colors.white,
          title: const Text("Paul's Dashatar App"),
          centerTitle: true,
        ),
        body: Center(
          child: Image.asset('images/mydashatar.png'),
        ),
      ),
    ),
  );
}
