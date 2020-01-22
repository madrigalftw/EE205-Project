///////////////////////////////////////////
///	THIS IS AN INCOMPLETE GAME	///
///////////////////////////////////////////

The following files contain the Console as well as the partially completed 
Advance Wars X game. 

To compile an executable, use the command "make console".

Make sure that SFML is installed on your device.

Due to time constraints, the "Adventures of Bard" game was not able to be
converted to a game that matches the requirements from the interface. It
will thus be sent in as a separate game/project.

WHAT YOU CURRENTLY CAN DO WITH THE EXECUTABLE:
==Console==
- Create a new game and load it onto the vector of games 
	- Select the game using the number pad

==Advance Wars X==
- Displays the tilemap
- Displays the underlying units/buildings on a separate screen to show stats
- Move cursor
- Select own units
	- Move own units

WILLY'S THOUGHTS ABOUT THE CODE:
When I first thought about the project, I believed that it would be 
pretty easy to create a little console, and then me and my partner 
would be able to work on individual games to add to the console. 
Thinking about the game I was responsible for "Advance Wars X (AWX),"
before starting the code, I thought of the basic functionalities, but 
not in depth. 

Problems I encountered early on when creating the console was
understanding the API and dealing with the issue of being able to 
click the "X" to exit the window once a game has been selected.

Once these issues were resolved, I was tasked with constructing a 
game with some interesting properties. Highlighting area of
movement, being able to move units within the highlighted area, 
etc. However, when developing the functions, I poorly planned 
the classes, the inputs to the functions, and the outputs. As a
result, the code became extremely convoluted (most likely using 
memory needlessly), making it difficult to instantiate a single 
function. Consequently, most of the desired functions were
not implemented.

Looking forward to future projects, this project has made me realize 
the importance of carefully planning out classes and functions 
beforehand to avoid the problems mentioned above.
