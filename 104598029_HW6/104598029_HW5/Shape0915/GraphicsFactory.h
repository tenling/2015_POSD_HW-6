#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Graphics.h"
#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"

using namespace std;
class GraphicsFactory {
public:
  Graphics * buildGraphicsFromFile(const char * fileName); /*implement the pseudo code */
  string fileContentsAsString(const char * fileName); /* implement line 1 of pseudo code */
  Graphics * extractGraphicsFromOneLine(std::string & contents, int & level); /*implement line 3 */
  void compose (); /* implement lines 5, 6 as well as line 9 */
private:
  stack <Graphics *> g_s;
};

#endif // GRAPHICSFACTORY_H_INCLUDED
