#include "gui.moc"
#include "GraphicsScene.cpp"
#include "stateVisitor.cpp"

gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    CreateToolBars();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    Display();

    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);

}

gui::~gui()
{
    delete widget;
    delete scene;
    //dtor
}

void gui::CreateView(){
    widget = new QWidget();
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new GraphicsScene( graphicsView );
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void gui::SetActionConnection() {
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openfile()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(savefile()));
    connect(upAct, SIGNAL(triggered()), this, SLOT(up()));
    connect(downAct, SIGNAL(triggered()), this, SLOT(down()));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));
}

void gui::CreateActions() {
        aboutDeveloper = new QAction("aboutDeveloper", widget);
        saveAct= new QAction(QIcon("./images/save.png"), tr("&SaveFile"), this);
        openAct= new QAction(QIcon("./images/open.png"), tr("&openFile"), this);
        upAct= new QAction(QIcon("./images/up.png"), tr("&up"), this);
        downAct= new QAction(QIcon("./images/down.png"), tr("&down"), this);
        redoAct= new QAction(QIcon("./images/redo.png"), tr("&redo"), this);
        undoAct= new QAction(QIcon("./images/undo.png"), tr("&undo"), this);
}

void gui::CreateMenus() {
     file = menuBar()->addMenu("File");
     file->addAction(openAct);
     file->addAction(saveAct);
     about = menuBar()->addMenu("About");
     about->addAction(aboutDeveloper);
}

void gui::CreateToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar-> addAction(openAct);
    fileToolBar-> addAction(saveAct);
    fileToolBar-> addAction(upAct);
    fileToolBar-> addAction(downAct);
    fileToolBar-> addAction(undoAct);
    fileToolBar-> addAction(redoAct);
}
void gui::Display() {
    graphicsView->setScene(scene);
    scene->update();
}

void gui::saveGraphics(){
    Graphics* g = graphics.front();
    DescriptionVisitor dv;
    g->accept(dv);
    undo_vector.push_back(dv.getDescription());
    cout << "Save Graphics : " << undo_vector.size() << endl;
    cout << "Save : " << dv.getDescription() << endl;
}

void gui::MessageDialog() {
    QMessageBox msgbox;
    std::string message("104598029\n");
    message += std::string("author:Tenling");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}

void gui::openfile(){
    graphicsView->scene()->clear();
    Display();
    QString fileName= QFileDialog::getOpenFileName(this,tr("Load File Dialog"),"",tr("Text Files (*.txt)"));
    if(!fileName.isEmpty()){
        curFile=fileName;
        loadFile();
        graphicsView->setScene(scene);
        Display();
        saveGraphics();
    }
}

void gui::loadFile(){
    QFile file(curFile);
    GraphicsFactory gf;
    QTVisitor qtVisitor(widget,scene);
    if(file.open(QFile::ReadOnly)){
        gf.buildGraphicsFromFile(curFile.toLocal8Bit().data());
        graphics = gf.getGraphics();
        file.close();
        Graphics *temp;
        for(std::list<Graphics*>::iterator it = graphics.begin(); it!=graphics.end(); ++it){
            temp = *it;
            temp->accept(qtVisitor);
        }
        QList <QGraphicsItem *> graphicsitem_list;
        graphicsitem_list = scene->items();
        scene = qtVisitor.getQGraphicsScene();
        Display();
    }
}

void gui::savefile(){
    QString fileName= QFileDialog::getSaveFileName(this,tr("Save File Dialog"),"",tr("Text Files (*.txt)"));
    DescriptionVisitor dv;
    Graphics *temp;
    QList<QGraphicsItem *> items = scene->items();
    GraphicsItem *temp_item;
    for(std::list<Graphics*>::iterator it = graphics.begin(); it!=graphics.end(); ++it){
        temp = *it;
        temp->accept(dv);
    }
    fstream file;
    file.open(fileName.toLocal8Bit().data(),ios::out|ios::trunc);
    if(file){
        file << dv.getDescription();
        file.close();
        graphicsView->scene()->clear();
        Display();
        saveGraphics();
    }
}


void gui::undo(){
    if(!undo_vector.empty()){
        QTVisitor qtv(widget,scene);
        GraphicsFactory gf;
        fstream file;
        string description =  undo_vector.back();
        file.open("tempGraphics",ios::out|ios::trunc);
        if(file){
            file << description;
            file.close();
        }
        gf.buildGraphicsFromFile("tempGraphics");
        graphics = gf.getGraphics();
        graphics.front()->accept(qtv);
        scene = qtv.getQGraphicsScene();
        Display();
        redo_vector.push_back(undo_vector.back());
        undo_vector.pop_back();
    }
    else{
        cout << "Cannot undo!" <<endl;
    }

}
void gui::redo(){
    if(!redo_vector.empty()){
        QTVisitor qtv(widget,scene);
        GraphicsFactory gf;
        fstream file;
        string description =  redo_vector.back();
        file.open("tempGraphics",ios::out|ios::trunc);
        if(file){
            file << description;
            file.close();
        }
        gf.buildGraphicsFromFile("tempGraphics");
        graphics = gf.getGraphics();
        graphics.front()->accept(qtv);
        scene = qtv.getQGraphicsScene();
        Display();
        undo_vector.push_back(redo_vector.back());
        redo_vector.pop_back();
    }
    else{
        cout << "Cannot redo!" <<endl;
    }
}
void gui::up(){
    scene = (GraphicsScene *)graphicsView->scene();
    QList<QGraphicsItem *> selectitems = scene->selectedItems();
    if(selectitems.length() == 0){
        cout << "Error select!" << endl;
    }
    else{
        saveGraphics();
        GraphicsItem* selectitem = (GraphicsItem *)selectitems.front();
        while(!selectitems.empty()){
            GraphicsItem* temp = (GraphicsItem *)selectitems.front();
            selectitems.pop_front();
        }
        QList<QGraphicsItem *> sceneitem = scene->items();
        GraphicsItem* comp_item = (GraphicsItem*)sceneitem.front();
        Graphics *g = selectitem->getGraphcis();
        // 0 stand for up
        stateVisitor sv(g,graphics.front(),0);
        graphics.front()->accept(sv);
        DescriptionVisitor dv;
        graphics.front()->accept(dv);
        cout << dv.getDescription() << endl;
        graphicsView->scene()->clear();
        scene = (GraphicsScene *)graphicsView->scene();
        QTVisitor qtv(widget,scene);
        for(std::list<Graphics*>::iterator it = graphics.begin(); it!=graphics.end(); ++it){
            (*it)->accept(qtv);
        }
        scene = qtv.getQGraphicsScene();
        Display();
    }
}
void gui::down(){

    scene = (GraphicsScene *)graphicsView->scene();
    QList<QGraphicsItem *> selectitems = scene->selectedItems();
    if(selectitems.length() == 0){
        cout << "Error select!" << endl;
    }
    else{
        saveGraphics();
        GraphicsItem* selectitem = (GraphicsItem *)selectitems.front();
        while(!selectitems.empty()){
            GraphicsItem* temp = (GraphicsItem *)selectitems.front();
            selectitems.pop_front();
        }
        QList<QGraphicsItem *> sceneitem = scene->items();
        GraphicsItem* comp_item = (GraphicsItem*)sceneitem.front();
        Graphics *g = selectitem->getGraphcis();
        // 1 stand for down
        stateVisitor sv(g,graphics.front(),1);
        graphics.front()->accept(sv);
        DescriptionVisitor dv;
        graphics.front()->accept(dv);
        cout << dv.getDescription() << endl;
        graphicsView->scene()->clear();
        scene = (GraphicsScene *)graphicsView->scene();
        QTVisitor qtv(widget,scene);
        for(std::list<Graphics*>::iterator it = graphics.begin(); it!=graphics.end(); ++it){
            (*it)->accept(qtv);
        }
        scene = qtv.getQGraphicsScene();
        Display();
    }
}
