# RoboticArena
Project where user via command line can control a given number of 'robots' which are located on the 'arena'.

## Ok, but how does it actually work?

### System requirements
For this project you are obligated to use program **gnuplot** with **Linux** operating system. Either you can download it from [this website](http://www.gnuplot.info/download.html), or just simply use command:
>_apt-get install gnuplot_

This is because program has a communication module that operates only on the Linux OS.

### Now let's get to details
* On the start of the program, in the cartesian coordinates there are several default robots created, as well as some obstacles.
* User is equipped in some commands that he can use:
  * adding a new robot or an obstacle
  * changing the robot that is in control right now
  * moving straight by the given distance
  * rotation by the given angle
  * changing the size of a robot
  * changing the speed of robot movement
* Yes, there was a 'speed' word! There are built-in animations, of rotation and movement.
* User can end the program at any given moment.

## Authors
**Dr. inż. Bogdan Kreczmer, profesor of Wroclaw University of Science** -> The initial idea and basic view of how the program should look like and how should be constructed. 
* [Link](http://rab.ict.pwr.wroc.pl/~kreczmer/po/) to the Dr. Bogdan's website, where you can find all the materials on which the program is based. The materials are authored by him as well!
* Files: _lacze_do_gnuplota.cpp_ and _lacze_do_gnuplota.hh_ are written only by Dr. Kreczmer and he is an only author to them!

**Aleksander Pucher** -> All the other code in the program. 



