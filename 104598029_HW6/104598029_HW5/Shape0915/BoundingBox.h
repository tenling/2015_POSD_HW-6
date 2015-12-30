#ifndef BOUNDINGBOX_H_INCLUDED
#define BOUNDINGBOX_H_INCLUDED

class BoundingBox{
private:
    int ll_x;
    int ll_y;
    int ur_x;
    int ur_y;
    int arean;
public:
    BoundingBox(int ll_x,int ll_y,int ur_x,int ur_y,int area);
    int llx();
    int lly();
    int urx();
    int ury();
    int area();
};


#endif // BOUNDINGBOX_H_INCLUDED
