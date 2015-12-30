#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED
#include "Graphics.h"
#include <vector>

class GraphicsVisitor;
class CompositeGraphics: public Graphics{
public:
    CompositeGraphics();
    CompositeGraphics(int level);
    void add(Graphics *g);
    void accept(GraphicsVisitor &g);
private:
    std::vector<Graphics *> gv;
};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
