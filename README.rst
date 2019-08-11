TicTacToe robots
================

This project is kind of a test and training working with c++. 
The task is to create different AIs and KIs playing against each other TicTacToe.

How to contribute
-----------------
I'm looking forward to your robots fighting each other ;)
But in the first place, you have to contribute and that's pretty easy.

The three times three field is at the moment implemented as a two-dimensional char array. ::
The order is self-explaining: each array in the first dimension is a row.

  char square[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  
  
If you want to add a new player, you have to create an instance of the class *Player*. Here you have a simple example of such an instance.
Also, you should take a look to the headerfile *Players.h* and add your class structure. 
To select your robot to add a new case to the switch statement at the method *selectPlayer* and the signature of your robot at the main method of *TicTacToe.cpp*.

I would be happy if you add the name of the robot and yours to the *Robots.rst* file ;)

Happy coding!
