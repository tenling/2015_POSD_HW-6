#ifndef GUI_H
#define GUI_H
#include <QtWidgets/QMainWindow>
#include <Qt>
#include <QGraphicsView>
#include <QtWidgets/QToolBar>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QList>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

#include "GraphicsFactory.h"
#include "GraphicsVisitor.h"
#include "DescriptionVisitor.h"
#include "QTVisitor.h"
#include "GraphicsScene.h"

using namespace std;


class gui: public QMainWindow
{
    Q_OBJECT
    public:
        gui();
        virtual ~gui();
        QGraphicsView *graphicsView;
        GraphicsScene *scene;
        QWidget *widget;

        void Display();
        void CreateView();
        void CreateActions();
        void CreateMenus();
        void CreateToolBars();
        void SetActionConnection();
        void loadFile();
        void saveFile(const QString &filename);

    protected:

    private:
        QString curFile;
        QAction *aboutDeveloper;
        QAction *saveAct;
        QAction *openAct;
        QAction *createCircleAct;
        QAction *createSquareAct;
        QAction *createRectangleAct;
        QAction *groupAct;
        QAction *ungroupAct;
        QAction *redoAct;
        QAction *undoAct;
        QMenu *file;
        QMenu *about;
        QMenu *create;
        QToolBar *fileToolBar;
        std::list<Graphics*> graphics;

    private slots:
        void MessageDialog();
        void openfile();
        void savefile();
        void createCircle();
        void createRectangle();
        void createSquare();
        void group();
        void ungroup();
};

#endif // GUI_H
