#ifndef UTVISITOR_H_INCLUDED
#define UTVISITOR_H_INCLUDED

#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Graphics.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "util.h"
#include <string>
#include <vector>
#include "AreaVisitor.h"
#include "DescriptionVisitor.h"


TEST (AreaVisitor, Simple) {
    SimpleGraphics s(new Rectangle(0,0,2,3));
    AreaVisitor av;
    s.accept(av);

    LONGS_EQUAL(6,av.area());
}


TEST (AreaVisitor, Composite) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    AreaVisitor av;
    g.accept(av);

    LONGS_EQUAL(7,av.area());

    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    AreaVisitor av2;
    h.accept(av2);

    LONGS_EQUAL(10,av2.area());
}


TEST(AreaVisitor, derivedFromGraphicsVisitor) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    SimpleGraphics r(new Rectangle (-1,-1,1,3));
    CompositeGraphics h;

    h.add(&g);
    h.add(&r);

    GraphicsVisitor * av = new AreaVisitor;
    h.accept(*av);

    LONGS_EQUAL(10, static_cast<AreaVisitor *>(av)->area());
}

TEST (Shape, descriptions) {
    Shape * c = new Circle(0,0,1);
    CHECK(std::string("C(0,0,1)")== c->describe());
    c = new Square(0,0,1);
    CHECK(std::string("S(0,0,1)")== c->describe());
    c = new Rectangle(0,0,1,2);
    CHECK(std::string("R(0,0,1,2)")== c->describe());
}

TEST (DescVisitor, SimpleGraphics) {
    SimpleGraphics s(new Rectangle(0,0,2,3));
    DescriptionVisitor dv;
    s.accept(dv);

    CHECK(std::string("R(0,0,2,3)\n")==dv.getDescription());
}

TEST (DescVisitor, CompositeGraphics) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    DescriptionVisitor dv;
    g.accept(dv);

    std::string ans("Comp R(-2,-2,3,3)\n");
    ans += std::string("  C(0,0,1)\n");
    ans += std::string("  S(-2,-2,2)\n");
    CHECK(ans==dv.getDescription());
}

TEST (DescVisitor, CompositeGraphicsWithComposite) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    DescriptionVisitor dv;
    h.accept(dv);

    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    CHECK(ans==dv.getDescription());
}

#endif // UTVISITOR_H_INCLUDED
