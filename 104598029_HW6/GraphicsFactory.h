#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED

#include "Graphics.h"
#include "SimpleGraphics.h"
#include <stack>
#include <string>
#include <utility>
#include <QPair>
#include <list>

using namespace std;

class GraphicsFactory {
public:
    void buildGraphicsFromFile(const char * fileName); /*implement the pseudo code */
    void buildGraphicsFromString(string description);
    string fileContentsAsString(const char * fileName); /* implement line 1 of pseudo code */
    Graphics * extractGraphicsFromOneLine(string & contents, int & level); /*implement line 3 */
    void compose (); /* implement lines 5, 6 as well as line 8 */
    SimpleGraphics * buildSimpleGraphics(string &contents);
    std::list <Graphics *>getGraphics();
public:
    stack<QPair<int, Graphics * > > pda;
    std::list <Graphics*> graphics_list;
};


#endif // GRAPHICSFACTORY_H_INCLUDED
