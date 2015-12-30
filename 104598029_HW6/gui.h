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
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "GraphicsFactory.h"
#include "GraphicsVisitor.h"
#include "DescriptionVisitor.h"
#include "QTVisitor.h"
#include "stateVisitor.h"
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
        void saveGraphics();

    protected:

    private:
        QString curFile;
        QAction *aboutDeveloper;
        QAction *saveAct;
        QAction *openAct;
        QAction *upAct;
        QAction *downAct;
        QAction *undoAct;
        QAction *redoAct;
        QMenu *file;
        QMenu *about;
        QToolBar *fileToolBar;
        std::list<Graphics*> graphics;
        std::vector<string> undo_vector;
        std::vector<string> redo_vector;

    private slots:
        void MessageDialog();
        void openfile();
        void savefile();
        void undo();
        void redo();
        void up();
        void down();
};

#endif // GUI_H
