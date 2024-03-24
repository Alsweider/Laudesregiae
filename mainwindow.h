#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <random>
#include <QScreen>
#include <QFontDatabase>
#include <QApplication>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void einlesen();
    QString dateiName;
    //für die Datei
    QFile *datei;
    QTimer* timer;
    QTimer* leerTimer;
    QTextStream in;
    void setzeZufallsPosition();
    void loadSettings();
    void saveSettings();
    QString settingsFile;
    bool randomorder, looptext;
    QString font;
    double displayDuration, faktor;
    int pausemin, pausemax;
    QSettings settings;
    void ausgabeSchleife();
    int calculatePauseTime(int, int);
    int x,y; //Label-Koordinaten
    QStringList lines;
    int fontsize;
    QString colourText, colourBackground;
    QString convertHexToRGB(QString);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void Leeren();
    void Ausgeben();
};
#endif // MAINWINDOW_H
