#include "Graphics.h"
#include "GraphicsVisitor.h"
#include <string>
Graphics::Graphics(){
    box=new BoundingBox(0,0,0,0,0);
}
BoundingBox Graphics::getBoundingBox(){
    return *box;
}
void Graphics::add(Graphics *g){
}
void Graphics::accept(GraphicsVisitor &g){
}
std::string Graphics::describe(){
    return G_description;
}
