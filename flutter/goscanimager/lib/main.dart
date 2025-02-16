import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.black,
          foregroundColor: Colors.white,
          centerTitle: true,
          title: const Text(
            "GoScan :: Image Acquisition",
            style: TextStyle(color: Colors.blueAccent, fontSize: 30.0),
          ),
        ),
        body: Center(
          child: Image.network("https://www.goscan.com/images/logo.jpg"),
        ),
      ),
    ),
  );
}
