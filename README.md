# The Claremont Trials - Final Project

## CSCI 56 Object Oriented Game Development, Spring 2019

### Group members:
###     Jonathan Bueff (leader)
###     Eric Nguyen
###     Ryan Cullen
###     Sydney Baffour



### A Brief Description of the Game
The game is called The Claremont Trials. The player is a student at the Claremont Colleges who is struggling to maintain a high GPA. He's had enough of his poor performance, and has decided to become a straight-A student. Help the student raise his GPA from a 2.00 by shooting the A homeworks from the sky. Collect them all to earn a 4.00 GPA.

### The Controls
- On the main menu, select "Exit Game" to quit the game, or, select "Play Game" to start the game 
- To move, use the left and right arrow keys
- To shoot, use the space bar. Only two bullets can exist on the screen at once. Use them wisely!
- To pause the game while playing, press "P". Options to "Resume Game", or "Quit Game" will then be available
- Once the game is finished, the game will exit by itself (or you can exit manually by closing the application). If you beat the high score, your score will become the new high score 

### Special Compilation Instructions
To compile the game, you're going to need four frameworks from SDL2. These frameworks are:
1. SDL2
2. SDL2_image
3. SDL2_ttf
4. SDL2_mixer

Place these frameworks where your other frameworks are. For MacOS users, this is typically /Library/Frameworks. Once you've downloaded the frameworks, open a terminal, and change your directory to the game directory. Then, run the following command:

clang++ -F /Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer -std=c++11 *.cpp && ./a.out

Replace /Library/Frameworks with the path to your frameworks if your frameworks do not reside in /Library/Frameworks.

### Acknowledgment of Outside Sources
We acknowledge Ather Omar's SDL 2.0 Tutorial series on YouTube. All code provided by Omar has been commented as so. 

### Satisfaction of Programming Requirements Mentioned in Section 1:

#### 1. Polymorphism
Our code implements polymorphism for multiple classes. The game utilizes the class "Game Entity" to implement the other classes such as Bullet, Player, and Texture. Each class uses GameEntity and relies on its methods as well. This was ciritcal when creating our other classes.
#### 2. At least 2 design patterns
The two design patterns implemented in this game were:
- The Singleton Design Patter: This is implemented in our "Graphics" class. We implement the singleton pattern becasue we only needed one instance of the class which held the dimensions for the window and the back buffer. This allowed us to use Graphics anytime we needed to interact or add something to the screen. 

- The Factory Pattern: We used the Factor pattern in our Texture class. The Texture class acted as the parent class to the AnimatedTexture class which was used for the moving elements of the game like the Player, Assignments and Bullets.
#### 3. File I/O
In terms of file input and output, our game stores a players individual high score and outputs the number at the top of the game. Each game, the player starts with a base score of 200( to be interpreted as 2.0). The maximum score a player can recieve is a 400, or a 4.0, which represents the highest GPA one can recieve. 
#### 4. Operator overloading
In our Player, Bullet, and Enemy classes we ovverride the GameEntity classes Render and Update fucntions. 

#### 5. Memory management 
Every class contains a constructor and a destructor in order to properly manage the memory allocations for each element of the game. 
#### 6. Good programming style
Our team focused on implementing coding skills taught in class to maintain good coding style and practice. Additionally, all code has been properly formmatted and commented to ensure readability. 
### Additional Information 
Each student brought their own style and ability to the making of this game. Breif recognition to Ryan cullen who indicidually created all of the sprites to make the game unique! 
