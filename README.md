# ToyRobot
TOY ROBOT CODE CHALLENGE
------------------------
Problem
-------
 1. Simulating a Toy Robot moving on a square table top of dimension 5 units x 5 units. No obstructions on the table surface.
 2. The robot is free to roam around the surface but must not fall to destruction.
 3. Any movement that result in the robot falling from the table must be prevented. However further valid movement must still be allowed.
 5. Create a Console Application that can read in commands of the following form:
    PLACE X,Y,F
    MOVE
    LEFT
    RIGHT
    REPORT
    EXIT
 7. PLACE will put the robot in position X,Y and facing NORTH, SOUTH, EAST or WEST.
 8. The origin (0,0) can be considered to be SOUTH WEST most corner.
 9. PLACE command must be the first command. After that any command can be issued in any order.
10. Discard all commands until a valid PLACE command has been executed.
11. MOVE will move the robot one unit forward in the direction it is currently facing.
12. LEFT and RIGHT will rotate the robot 90 degress in the specified direction without changing the position of the robot.
13. REPORT will announce the X,Y and F of the robot. This can be in any form.
14. A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
15. Input can be from a file, or from standard input, as the developer chooses.
16. Provide test data to exercise the application.
17. The application should handle error states appropriately and be robust to user input.
18. Robot must not fall off the table during movement including the initial placement of the robot.
19. Any move that would cause the robot to fall must be ignored.

   Examples:

    ---- Example 1 ----		   
    PLACE 0,0,NORTH
    MOVE
    REPORT
    ---- Expected Output --- 
    0,0,NORTH

    ---- Example 2 ----		   
    PLACE 0,0,NORTH
    LEFT
    REPORT
    ---- Expected Output --- 
    0,0, WEST

    ---- Example 3 ----		   
    PLACE 1,2,EAST
    MOVE
    MOVE
    LEFT
    MOVE
    REPORT
    ---- Expected Output --- 
    3,3,NORTH


Solution
--------
1. The solution is developed using Microsoft Visual C++ 2019
2. Unit testing using Microsoft Native C++ Unit Testing Framework which is already included with Visual Studio 2019. No additional downloads required.
3. The main solution file is ToyRobot.sln. There are 3 projects folders: ToyRobotApp (application), ToyRobotLib (static library), and ToyRobotUnitTest (UnitTest).
   The source codes related to each project are located in the same project folder.

Git
---
1. Clone the repository into your local drive.
2. Or download the zip file and unzip into your local drive.

Building the solution
---------------------
Building the solution is as simple as opening the solution file from Visual Studio 2019 and the do the build.

Running the application
-----------------------
1. The executable file which can be run as a standard console application by typing this command at the folder where it resides ".\ToyRobotApp".
2. Or it can be run using a command file containing a list of command. For example, if the command file is CommandFile.txt then it can be run by typing this command: ".\ToyRobot CommandFile.txt"
3. CommandFile.txt should contains a list of commands like they are entered via the console.
4. Unit Testing can be done from within Visual Studio 2019 Test Explorer window.




