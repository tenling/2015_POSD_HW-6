//#incldue "Mainpage.moc"
#include "Mainpage.h"

Mainpage::Mainpage(){
    textEdit = new QPlainTextEdit;
    setCentralWidget(testEdit);

    createAction();
    createMenus();
    createToolBars();
    createStatusBars();

    readSetting();

    connect(textEdit->document(), SIGNAL(ContentsRectChange), this , SLOT(documentWasModified()));

    setCurrentFile("");
    setUnifiedTitleAndToolBarOnMac(true);

}

void Mainpage::closeEvent(QCloseEvent *event){

    if(maybeSave()){
        writeSetting();
        event->accept();
    }else{
        event->ignore();
    }
}

void Mainpage::open(){
    if(maybeSave()){
        QString fileName= QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty()){
            loadFile();
        }
    }
}

bool Mainpage::save(){
    if(curFile.isEmpty()){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}

void Mainpage::about(){
    QMessageBox::about(this, tr("104598029 \n author:Tenling");
}

void Mainpage::createAction(){
    openAct= new QAction(QIcon(":/images/open.png"), tr("&open..."), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(te("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct= new QAction(QIcon(":/images/save.png"), tr("&SaveAs..."), this);
    saveAct->setShortcut(QKeySequence::save);
    saveAct->setStatusTip(te("Save file"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    aboutAct= new QAction(tr("&aboutDeveloper"), this);
    connect(aboutAct,SIGNAL(triggered()),this,SLOT(about()));
}

void Mainpage::createMenus(){
    fileMenu= menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(openAct);
    aboutMenu= menuBar()->addMenu(tr("&Help"));
    aboutMenu->addAction(aboutAct);
}

void Mainpage::createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar-> addAction(openAct);
    fileToolBar-> addAction(saveAct);
}

void Mainpage::createStatusBars(){
    statusBar()->showMessage(tr("Ready"));
}

void Mainpage::readSetting(){
    QSetting settings("QtProject", "Sample");
    QPoint pos= settings.value("pos",QPoint(200,200)).toPoint();
    QSize size=settings.value("size", Qsize(400,400)).toSize();
    resize(size);
    move(pos);
}

void Mainpage::writeSetting(){
    QSetting settings("QtProject", "Sample");
    settings.setValue("pos", pos());
    settings.setValue("size",size());
}

bool Mainpage::maybeSave(){
    if(textEdit->document()->isModified()){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Warning")),tr("Do you want to save your changes?"),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox ::Cancel);

        if(ret == QMessageBox::Save){
            return save();
        }
        else if(ret == QMessageBox::Cancel){
            return false;
        }
        return true;
    }
}



