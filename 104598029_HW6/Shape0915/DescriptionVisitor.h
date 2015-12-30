#ifndef DESCRIPTIONVISITOR_H_INCLUDED
#define DESCRIPTIONVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
class DescriptionVisitor: public GraphicsVisitor{
public:
    DescriptionVisitor();
    void visitSimpleGraphics(SimpleGraphics *s);
    void visitCompositeGraphics(CompositeGraphics *c);
    std::string getDescription();
    void stateclose();
private:
    std::string d;
};

#endif // DESCRIPTIONVISITOR_H_INCLUDED
