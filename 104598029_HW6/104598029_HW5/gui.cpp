#include "gui.moc"
#include "GraphicsScene.cpp"

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
    graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
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
    connect(createCircleAct, SIGNAL(triggered()), this, SLOT(createCircle()));
    connect(createSquareAct, SIGNAL(triggered()), this, SLOT(createSquare()));
    connect(createRectangleAct, SIGNAL(triggered()), this, SLOT(createRectangle()));
    connect(groupAct,SIGNAL(triggered()), this, SLOT(group()));
    connect(ungroupAct,SIGNAL(triggered()), this, SLOT(ungroup()));
}

void gui::CreateActions() {
        aboutDeveloper = new QAction("aboutDeveloper", widget);
        saveAct= new QAction(QIcon("./images/save.png"), tr("&SaveFile"), this);
        openAct= new QAction(QIcon("./images/open.png"), tr("&openFile"), this);
        createSquareAct = new QAction(QIcon("./images/square.png"),tr("&Create Square"), this);
        createCircleAct = new QAction(QIcon("./images/circle.png"),tr("&Create Circle"), this);
        createRectangleAct = new QAction(QIcon("./images/rectangle.png"),tr("&Create Rectangle"), this);
        groupAct = new QAction(QIcon("./images/group.png"),tr("&Group Item"), this);
        ungroupAct = new QAction(QIcon("./images/ungroup.png"),tr("&Ungroup Item"), this);
        redoAct = new QAction(QIcon("./images/redo.png"),tr("&Redo"), this);
        undoAct = new QAction(QIcon("./images/undo.png"),tr("&Undo"), this);
}

void gui::CreateMenus() {
     file = menuBar()->addMenu("File");
     file->addAction(openAct);
     file->addAction(saveAct);
     file = menuBar()->addMenu("Create");
     file->addAction(createSquareAct);
     file->addAction(createRectangleAct);
     file->addAction(createCircleAct);
     about = menuBar()->addMenu("About");
     about->addAction(aboutDeveloper);
}

void gui::CreateToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar-> addAction(openAct);
    fileToolBar-> addAction(saveAct);
    fileToolBar->addAction(createSquareAct);
    fileToolBar->addAction(createCircleAct);
    fileToolBar->addAction(createRectangleAct);
    fileToolBar->addAction(groupAct);
    fileToolBar->addAction(ungroupAct);
    fileToolBar->addAction(redoAct);
    fileToolBar->addAction(undoAct);
}
void gui::Display() {
    graphicsView->setScene(scene);
    scene->update();
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
    while(!items.empty()){
        temp_item =(GraphicsItem *)items.front();
        temp_item->update_pos();
        items.pop_front();
    }
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
    }
}

void gui::createCircle(){
    string description="C(50,0,50)";
    SimpleGraphics *sg;
    GraphicsFactory gf;
    QTVisitor qtv(widget,scene);
    sg = gf.buildSimpleGraphics(description);
    sg->accept(qtv);
    scene = qtv.getQGraphicsScene();
    qtv.setScene(scene);
    Display();
}

void gui::createSquare(){
    string description="S(30,30,50)";
    SimpleGraphics *sg;
    GraphicsFactory gf;
    QTVisitor qtv(widget,scene);
    sg = gf.buildSimpleGraphics(description);
    sg->accept(qtv);
    scene = qtv.getQGraphicsScene();
    qtv.setScene(scene);
    Display();
}

void gui::createRectangle(){
    string description="R(90,90,100,50)";
    SimpleGraphics *sg;
    GraphicsFactory gf;
    QTVisitor qtv(widget,scene);
    sg = gf.buildSimpleGraphics(description);
    sg->accept(qtv);
    scene = qtv.getQGraphicsScene();
    qtv.setScene(scene);
    Display();
}


void gui::group(){
    scene =(GraphicsScene *) graphicsView->scene();
    int item_quantity = scene->selectedItems().length();
    QList<QGraphicsItem *> selectItem =scene->selectedItems();
    cout << "Group" << "Item :" << item_quantity << endl;
    if(item_quantity == 1){
        QMessageBox group_unsuccessful;
        group_unsuccessful.setText("Error, there is only one graphics has been selected!");
        group_unsuccessful.exec();
    }
    else{
        CompositeGraphics *cg = new CompositeGraphics();
        GraphicsGroupItem *groupitem = new GraphicsGroupItem(cg, widget);
        GraphicsItem *temp;
        while(!selectItem.empty()){
            temp = (GraphicsItem *)selectItem.front();
            temp->update_pos();
            cg->add(temp->getGraphcis());
            scene->removeItem(temp);
            groupitem->addToGroup(temp);
            selectItem.pop_front();
        }
        scene->addItem(groupitem);
        Display();

    }
}

void gui::ungroup(){
    scene =(GraphicsScene *) graphicsView->scene();
    int item_quantity = scene->selectedItems().length();
    QList<QGraphicsItem *> selectItem =scene->selectedItems();
    cout << "Group" << "Item :" << item_quantity << endl;
    if(item_quantity != 1){
        QMessageBox group_unsuccessful;
        group_unsuccessful.setText("Error, there is only one group can be ungroup!");
        group_unsuccessful.exec();
    }
    else{
        GraphicsItem *temp;
        temp = (GraphicsItem *)selectItem.front();
        scene->removeItem(temp);
        selectItem = temp->childItems();
        while(!selectItem.empty()){
            temp =(GraphicsItem *) selectItem.front();
            temp->update_pos();
            scene->addItem(selectItem.front());
            selectItem.pop_front();
        }
        Display();

    }
}
