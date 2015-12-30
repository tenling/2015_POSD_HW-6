#include "GraphicsFactory.h"

#include <vector>
#include <fstream>
#include <sstream>
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Graphics.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "util.h"



using namespace std;

void GraphicsFactory::compose () {
    vector<Graphics *> temp;
    int level = pda.top().first;
    for (; pda.top().first == level; pda.pop())
        temp.push_back(pda.top().second);
    if (pda.top().first == level-1) {
        vector<Graphics *>::reverse_iterator it = temp.rbegin();
        for (; it != temp.rend(); ++it) {
            pda.top().second->add(*it);
        }
    }
}

string GraphicsFactory::fileContentsAsString(const char * fileName) {
	ifstream ifs(fileName);
	if (!ifs)
        throw "Problem opening file";

    string contents("");
    string s;
    while (getline(ifs,s))
    {
        contents.append(s);
        contents.append(string("\n"));
    }

	if (ifs.is_open())
		ifs.close();

    return contents;
}

Graphics * GraphicsFactory::extractGraphicsFromOneLine(std::string & contents, int & level) {
    std::size_t pos = contents.find_first_not_of(space);
    level = pos/2;
    Graphics * gr =0;

    std::size_t found = contents.find("Comp ", pos);
    if (found==pos)
        gr = new CompositeGraphics;
    found = contents.find("C(", pos);
    if (found==pos) {
        std::string s(contents.substr(pos+2));
        std::stringstream ifs(s);
        int cx, cy, r;
        char c;
        //     cx    ,    cy    ,    r    )
        ifs >> cx >> c >> cy >> c >> r >> c;
        gr = new SimpleGraphics(new Circle(cx,cy,r));
    }
    found = contents.find("S(", pos);
    if (found==pos) {
        std::string s(contents.substr(pos+2));
        std::stringstream ifs(s);
        int llx, lly, length;
        char c;
        //     llx    ,    lly    ,    length    )
        ifs >> llx >> c >> lly >> c >> length >> c;
        gr = new SimpleGraphics(new Square(llx, lly,length));
    }

    found = contents.find("R(", pos);
    if (found==pos) {
        std::string s(contents.substr(pos+2));
        std::stringstream ifs(s);
        int llx, lly, length, width ;
        char c;
        //     llx    ,    lly    ,    length    ,    width    )
        ifs >> llx >> c >> lly >> c >> length >> c >> width >> c;
        gr = new SimpleGraphics(new Rectangle(llx, lly,length,width));
    }

    pos=contents.find_first_of(newline, 0);
    contents = contents.substr(pos+1);

    if (gr)
        return gr;
    else
        throw std::string("undefined graphics");
}

void GraphicsFactory::buildGraphicsFromFile(const char * fileName) {
    Graphics * gr = 0;
    int indent_previous, indent_actual;
    std::string contents = fileContentsAsString(fileName);
    Graphics * top = extractGraphicsFromOneLine(contents, indent_actual);
    if (indent_actual != 0)
        throw std::string("Graphics format error");
    else {
        pda.push(qMakePair(indent_actual,top));
    }
    while (!contents.empty()) {
        indent_previous = indent_actual;
        Graphics * t = extractGraphicsFromOneLine(contents, indent_actual);
        if (indent_actual < indent_previous)
            compose();
        pda.push(qMakePair(indent_actual,t));
    }
    if (contents.empty()) {
        while (pda.size() > 1){
             if(pda.top().first!=0){
                compose();
             }
             else{
                graphics_list.push_back(pda.top().second);
                pda.pop();
             }
        }
        gr = pda.top().second;
    }
    graphics_list.push_back(gr);
}

SimpleGraphics* GraphicsFactory::buildSimpleGraphics(string &contents){
    SimpleGraphics* sg;
    stringstream ss;
    ss << contents;
    int num[4];
    char temp;
    //c(50,50,0)
    ss >> temp >> temp >> num[0] >> temp >> num[1] >> temp >> num[2] >> temp >> num[3];
    if(contents[0] == 'R'){
        sg = new SimpleGraphics(new Rectangle( num[0] , num[1] , num[2] , num[3]));
    }
    if(contents[0] == 'C'){
        sg = new SimpleGraphics(new Circle( num[0] , num[1] , num[2]));
    }
    if(contents[0] == 'S'){
        sg = new SimpleGraphics(new Square( num[0] , num[1] , num[2]));
    }

    return sg;
}

std::list<Graphics*> GraphicsFactory::getGraphics(){
    return graphics_list;
}
