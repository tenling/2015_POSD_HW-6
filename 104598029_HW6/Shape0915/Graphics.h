#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include "BoundingBox.h"
#include <string>

class GraphicsVisitor;
class Graphics{
private:

public:
    Graphics();
    BoundingBox *box;
    int level;
    virtual BoundingBox getBoundingBox();
    virtual void add(Graphics *g);
    virtual void accept(GraphicsVisitor &g);
    std::string G_description;
    std::string describe();
};


#endif // GRAPHICS_H_INCLUDED
