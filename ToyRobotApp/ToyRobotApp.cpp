
#include <iostream>
#include "..\ToyRobotLib\CommandProcessor.h"
#include "..\ToyRobotLib\Direction.h"
#include "..\ToyRobotLib\Robot.h"

using namespace std;
using namespace ToyRobot;

int main(int argc, char* argv[])
{  
    int ReturnVal = 0;
    int XUnits = 5;
    int YUnits = 5;

    try
    {
        TableTop RobotTableTop(XUnits, YUnits);
        Direction RobotDirection;
        Robot ToyRobot(RobotTableTop, RobotDirection);

        if (argc > 1)
        {
            // Commands from file
            ifstream File(argv[1]);

            if (File.is_open())
            {
                while (File.good())
                {
                    string CommandLine;

                    do
                    {
                        CommandLine = "";

                        getline(File, CommandLine);

                        // Convert CommandLine to upper case
                        for_each(CommandLine.begin(), CommandLine.end(), [](char& c) { c = ::toupper(c); });

                        cout << CommandLine << endl;

                        if (!ToyRobot.ProcessCommandLine(CommandLine))
                        {
                            continue;
                        }

                    } while (CommandLine != "EXIT");

                }
            }
            File.close();

        }
        else
        {
            // Commands from console 
            cout << "Toy Robot Console Application" << endl << endl;
            cout << "Please enter the command to perform: PLACE X,Y,F | LEFT | RIGHT | MOVE | REPORT | EXIT" << endl;

            string CommandLine;

            do
            {
                CommandLine = "";

                getline(cin, CommandLine);

                // Convert CommandLine to upper case
                for_each(CommandLine.begin(), CommandLine.end(), [](char& c) { c = ::toupper(c); });

                if (!ToyRobot.ProcessCommandLine(CommandLine))
                {
                    continue;
                }

            } while (CommandLine != "EXIT");

        }
    }
    catch (...)
    {
        std::cerr << "Caught unknown exception" << std::endl;
        ReturnVal = 1;
    }

    return ReturnVal;
}
