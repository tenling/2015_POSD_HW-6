#ifndef UTHW3_H_INCLUDED
#define UTHW3_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include "Graphics.h"
#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "CompositeGraphics.h"
#include "CompositeGraphics.cpp"
#include "SimpleGraphics.h"
#include "SimpleGraphics.cpp"
#include "GraphicsVisitor.h"
#include "AreaVisitor.h"
#include "DescriptionVisitor.h"
#include "DescriptionVisitor.cpp"
#include "GraphicsFactory.h"
#include "GraphicsFactory.cpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

TEST(Shapes0915, first_success) {
    CHECK(true);
}

TEST(GraphicsFactory,buildGraphicsFromFile){
    char* fileName = "f1.txt";
    GraphicsFactory gf;
    Graphics* g;
    DescriptionVisitor dv;
    fstream file;
    try {
        file.open(fileName);
    } catch (string s){
        FAIL("File open fail!");
    }

    g = gf.buildGraphicsFromFile(fileName);
    g -> accept(dv);
    string ans("Comp R(-2,-2,3,4)\n");
    ans += string("  Comp R(-2,-2,3,3)\n");
    ans += string("    C(0,0,1)\n");
    ans += string("    S(-2,-2,2)\n");
    ans += string("  R(-1,-1,1,3)\n");
    CHECK(ans==dv.getDescription());
}

TEST(GraphicsFactory,fileContentsAsString){
    char* fileName = "f1.txt";
    GraphicsFactory gf;
    string contents;
    contents = gf.fileContentsAsString(fileName);
    string ans("0 Comp R(-2,-2,3,4)\n");
    ans += string("1   Comp R(-2,-2,3,3)\n");
    ans += string("2     C(0,0,1)\n");
    ans += string("2     S(-2,-2,2)\n");
    ans += string("1   R(-1,-1,1,3)\n");
    CHECK(ans==contents);
}

TEST(GraphicsFactory,extractGraphicsFromOneLine){
    Graphics* g;
    GraphicsFactory gf;
    DescriptionVisitor dv;
    string circle_create("C(-5,-5,5)");
    int level = 1;
    g = gf.extractGraphicsFromOneLine(circle_create,level);
    g->accept(dv);
    string ans("C(-5,-5,5)\n");
    CHECK(ans==dv.getDescription());

    char* fileName = "f3.txt";
    DescriptionVisitor dv1;
    g=gf.buildGraphicsFromFile(fileName);
    g->accept(dv1);
    ans.clear();
    ans += string("Comp R(-1,-1,2,2)\n");
    ans += string("  C(0,0,1)\n");
    CHECK(ans == dv1.getDescription());
}

TEST(GraphicsFactory,compose){
    char* fileName = "f4.txt";
    Graphics* g;
    GraphicsFactory gf;
    DescriptionVisitor dv;
    g=gf.buildGraphicsFromFile(fileName);
    g->accept(dv);
    string ans("Comp R(-2,-2,3,3)\n");
    ans += string("  C(0,0,1)\n");
    ans += string("  S(-2,-2,2)\n");
    CHECK(ans == dv.getDescription());

    fileName = "f1.txt";
    GraphicsFactory gf1;
    DescriptionVisitor dv1;
    g = gf1.buildGraphicsFromFile(fileName);
    g->accept(dv1);
    ans.clear();
    ans += string("Comp R(-2,-2,3,4)\n");
    ans += string("  Comp R(-2,-2,3,3)\n");
    ans += string("    C(0,0,1)\n");
    ans += string("    S(-2,-2,2)\n");
    ans += string("  R(-1,-1,1,3)\n");
    CHECK(ans==dv1.getDescription());
}

#endif // UTHW3_H_INCLUDED
