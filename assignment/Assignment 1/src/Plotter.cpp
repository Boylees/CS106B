#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    double x = 0.0, y = 0.0;  // 初始位置在 (0, 0)
    bool penDown = false;  // 初始状态为笔抬起
    PenStyle style = {1, "black"};  // 初始笔的宽度为1，颜色为黑色

    for (string line; getline(input, line); ) {
        Vector<string> tokens = stringSplit(line, " ");
        string command = tokens[0];

        if (command == "PenDown") {
            penDown = true;
        } else if (command == "PenUp") {
            penDown = false;
        } else if (command == "MoveAbs") {
            double newX = stod(tokens[1]);
            double newY = stod(tokens[2]);
            if (penDown) {
                drawLine(x, y, newX, newY, style);
            }
            x = newX;
            y = newY;
        } else if (command == "MoveRel") {
            double dx = stod(tokens[1]);
            double dy = stod(tokens[2]);
            double newX = x + dx;
            double newY = y + dy;
            if (penDown) {
                drawLine(x, y, newX, newY, style);
            }
            x = newX;
            y = newY;
        } else if (command == "PenColor") {
            style.color = tokens[1];
        } else if (command == "PenWidth") {
            style.width = stod(tokens[1]);
        }
    }

}
