#ifndef GUI_H
#define GUI_H
#include <QtWidgets/QMainWindow>
#include <Qt>
#include <QGraphicsView>
#include <QtWidgets/QToolBar>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>
#include <QWidget>

class Mainpage : public QMainWindow{
    Q_OBJECT
public:
    Mainwindows();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void open();
    void save();
    void about();

private:
    void createMenus();
    void createAction();
    void createToolBars();
    void createStatusBars();
    void readSetting();
    void writeSetting();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &filename);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *testEdit;
    QString curFile;

    QMenu *fileMenu;
    QMenu *aboutMenu;
    QToolBar *fileToolBar;
    QAction *openAct;
    QAction *saveAct;
    QAction *aboutAct;
};

#endif // MAINPAGE_H_INCLUDED
