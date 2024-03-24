#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //100 % durschsischdisch!
    setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::MSWindowsFixedSizeDialogHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //Einstellungen laden
    settingsFile = QApplication::applicationDirPath() + "/settings.ini";
    saveSettings();
    loadSettings();
    qDebug() << "Speed-Einstellung: " << speed << "\n";

    QFontDatabase::addApplicationFont(":/new/ressourcen/carolingia.ttf");

    dateiName = QCoreApplication::applicationDirPath() + "/Eingabetext.txt";

    qDebug() << "Dateiname: " << dateiName << '\n';
    datei = new QFile(dateiName);

    if (QFile::exists(dateiName) == false)
    {
        setStyleSheet("");
        QMessageBox::information(this, "Hinweis", "Die Datei ist nicht vorhanden. "
                                                  "Bitte erstellen Sie eine Datei \"Eingabetext.txt\" im Programmordner "
                                                  "und starten Sie das Programm erneut.");
        close();
    }

    einlesen();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Ausgeben()));

    leerTimer = new QTimer(this);
    connect(leerTimer, SIGNAL(timeout()), this, SLOT(Leeren()));

    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Ausgeben(){
    qDebug() << "Ausgeben aufgerufen\n";

    if (loop == true) {
        do {
            ausgabeSchleife();
        } while (loop == true);
    } else {
        //Wenn loop nicht true ist, nur einmal durchlaufen
        ausgabeSchleife();
        timer->stop();
    }

    close();
    timer->stop();

}

void MainWindow::Leeren(){
    ui->label->clear();
    this->setStyleSheet("");
    ui->label->setStyleSheet("");
    update();
    leerTimer->stop();
}

void MainWindow::setzeZufallsPosition(){
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> distribution(0,10000);
    int zufall = distribution(engine);
    int zufall2 = distribution(engine);

    //Bildschirmgröße abrufen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();

    //Zufällige Position auf dem Bildschirm setzen
    x = zufall % (availableGeometry.width() - this->width());
    y = zufall2 % (availableGeometry.height() - this->height());

    this->move(x, y);
}


void MainWindow::loadSettings()
{
    qDebug() << "loadSettings() aufgerufen\n";
    QSettings setting(settingsFile, QSettings::IniFormat);
    setting.beginGroup("Settings");
    speed = setting.value("speed",143).toDouble();
    random = setting.value("random",false).toBool();
    loop = setting.value("loop",false).toBool();
    pause = setting.value("pausetime",1000).toInt();
    pausetimerandom = setting.value("pausetimerandom",setting.value("pausetime",1000)).toInt();
    font = setting.value("font","Carolingia").toString();
    fontsize = setting.value("fontsize","30").toInt();

    colourText = setting.value("colourtext","rgb(170, 0, 0)").toString();
    colourText = convertHexToRGB(colourText);

    colourBackground = setting.value("colourbackground","rgb(235, 213, 179)").toString();
    colourBackground = convertHexToRGB(colourBackground);

    setting.endGroup();

    qDebug() << "loadSettings() fertig ausgeführt.\n";
    qDebug() << "Speed: " << speed << '\n';
    qDebug() << "Random: " << random << '\n';
    qDebug() << "Loop: " << loop << '\n';
    qDebug() << "Pause: " << pause << '\n';
}

void MainWindow::saveSettings()
{
   qDebug() << "saveSettings() aufgerufen\n";
   QSettings setting(settingsFile, QSettings::IniFormat);
   setting.beginGroup("Settings");

   if (!setting.contains("speed")){
       setting.setValue("speed", 143);
       qDebug() << "\"speed\" hatte noch keinen Standardwert. Standard 143 festgelegt.\n";
   }

   if (!setting.contains("random")){
       setting.setValue("random", false);
       qDebug() << "\"random\" hatte noch keinen Standardwert. Standard \"false\" festgelegt.\n";
   }

   if (!setting.contains("loop")){
       setting.setValue("loop", false);
       qDebug() << "\"loop\" hatte noch keinen Standardwert. Standard \"false\" festgelegt.\n";
   }

   if (!setting.contains("pausetime")){
       setting.setValue("pausetime", 1000);
       qDebug() << "\"pausetime\" hatte noch keinen Standardwert. Standard 1000 festgelegt.\n";
   }

   if (!setting.contains("pausetimerandom")){
       setting.setValue("pausetimerandom", setting.value("pausetime"));
       qDebug() << "\"pausetimerandom\" hatte noch keinen Standardwert. Standardmäßig den Wert von \"pausetime\" festgelegt.\n";
   }

   if (!setting.contains("font")){
       setting.setValue("font","Carolingia");
       qDebug() << "\"font\" hatte noch keinen Standardwert. Standardmäßig die Schriftart \"Carolingia\" festgelegt.\n";
   }

   if (!setting.contains("fontsize")){
       setting.setValue("fontsize","30");
       qDebug() << "\"fontsize\" hatte noch keinen Standardwert. Standardmäßig 30 festgelegt.\n";
   }

   if (!setting.contains("colourtext")){
       setting.setValue("colourtext","#AA0000");
       qDebug() << "\"colourtext\" hatte noch keinen Standardwert. Standardmäßig die Farbe #AA0000 (rgb(170, 0, 0)) festgelegt.\n";
   }

   if (!setting.contains("colourbackground")){
       setting.setValue("colourbackground","#EBD5B3");
       qDebug() << "\"colourbackground\" hatte noch keinen Standardwert. Standardmäßig die Farbe #EBD5B3 (rgb(235, 213, 179)) festgelegt.\n";
   }


   setting.endGroup();
   qDebug() << "saveSettings() fertig ausgeführt.\n";

}


void MainWindow::ausgabeSchleife(){

    qDebug() << "Anzahl der Lines: " << lines.count() << "\n";

    // Wenn random auf true gesetzt ist, Zeilen mischen
    if (random == true) {
        qDebug() << "Zufallsreihenfolge festgelegt.\n";
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(lines.begin(), lines.end(), g);
    }

    // Zeige jede Zeile einzeln an
    for (const QString& line : lines) {

        //Stylesheet zusammensetzen
        QString stylesheetLabel = QString("font: %2pt \"%1\"; color: %3; background-color: %4").arg(font).arg(fontsize).arg(colourText).arg(colourBackground);
        ui->label->setStyleSheet(stylesheetLabel);

        //Bildschirmgröße abrufen
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect availableGeometry = screen->availableGeometry();

        QString displayText = line;

        QFontMetrics metrics(ui->label->font());
        int screenWidth = availableGeometry.width();
        int screenHeight = availableGeometry.height();
        qDebug() << "availableGeometry.width: " << availableGeometry.width() << '\n';
        qDebug() << "availableGeometry.height: " << availableGeometry.height() << '\n';
        qDebug() << "screenWidth: " << screenWidth << '\n';
        qDebug() << "screenWidth: " << screenHeight << '\n';
        qDebug() << "Fonthöhe: " << metrics.height() << '\n';
        qDebug() << "Font lineWidth: " << metrics.lineWidth() << '\n';

        //Maße ermitteln
        QRect boundingRect = metrics.boundingRect(displayText);
        int textWidth = boundingRect.width();
        int textHeight = boundingRect.height();
        qDebug() << "textWidth: " << textWidth << '\n';
        qDebug() << "textHeight: " << textHeight << '\n';

        //Text brechen, falls er größer als die Bildschirmbreite wird
        if (textWidth > screenWidth){
            //Zeilenumbruch
            ui->label->setWordWrap(true);

        } else{
            ui->label->setWordWrap(false);
        }
        ui->label->setText(displayText);

        //Hauptfenstergröße an Labelgröße anpassen
        ui->label->adjustSize();
        this->resize(ui->label->size() + QSize(20, 20)); //20px Raum hinzufügen

        setzeZufallsPosition();

        qDebug() << "label-Size: " << ui->label->size() << '\n';
        qDebug() << "Hauptfenster-Size: " << this->size() << '\n';

        //Schauen, ob wir über dem Rand sind
        //Position und Größe des Labels abrufen
        int labelX = ui->label->x();
        int labelY = ui->label->y();
        int labelWidth = ui->label->width();
        int labelHeight = ui->label->height();

        if ((labelX + labelWidth) > availableGeometry.width()) {
            qDebug() << "Morbleu, das Label ragt über den rechten Bildschirmrand hinaus." << '\n';
            ui->label->move(availableGeometry.width()-labelWidth,labelY);
        }

        if ((labelY + labelHeight) > availableGeometry.height()) {
            qDebug() << "Morbleu, das Label ragt über die Unterkante hinaus." << '\n';
            ui->label->move(labelX,availableGeometry.height()-labelHeight);
        }

        //Berechnen der Anzeigedauer basierend auf der Zeichenlänge
        if (speed != 0){
            faktor = speed;
        } else{
            faktor = 143;
        }
        int anzeigeDauer = (line.length() * faktor);

        //Pause berechnen
        int tempPause = calculatePauseTime(pause, pausetimerandom);

        qDebug() << "Text: " << line << '\n';
        qDebug() << "Line-länge: " << line.length() << '\n';
        qDebug() << "Anzeigedauer: " << anzeigeDauer << '\n';
        qDebug() << "Pause: " << tempPause << '\n';

        leerTimer->start(anzeigeDauer);

        // Warte, bis der Timer abgelaufen ist
        QEventLoop loop;
        connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        //Timer starten, um die Schleife zu beenden
        QTimer::singleShot(anzeigeDauer + tempPause, &loop, SLOT(quit()));

        loop.exec();
    }

}

//Überschriebenes closeEvent, um lose Enden zu verbinden.
void MainWindow::closeEvent(QCloseEvent *event){
    qDebug() << "Close-Event aufgerufen\n";
    loop = false;
    timer->stop();
    leerTimer->stop();

    //Und vergiss nicht, die Tür abzuschließen, ja?
    if(datei->isOpen()){
        qDebug() << "Datei war noch geöffnet. Na sowas...\n";
        datei->close();
    }
}

int MainWindow::calculatePauseTime(int zeit1, int zeit2){
    qDebug() << "calculatePauseTime aufgerufen\n";
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> distribution(zeit1,zeit2);
    int tempPause = distribution(engine);
    qDebug() << "Pause berechnet: " << tempPause << "\n";
    return tempPause;
}

void MainWindow::einlesen(){
    qDebug() << "Datei wird eingelesen.\n";
    // Öffnen und Einlesen der Datei
    datei->open(QIODevice::ReadOnly);
    in.setDevice(datei);

    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.append(line);
    }

    datei->close();
    qDebug() << "Datei geschlossen.\n";
}


QString MainWindow::convertHexToRGB(QString hexColour){
    QColor colour(hexColour);

    int red = colour.red();
    int green = colour.green();
    int blue = colour.blue();

    QString rgbColour = QString("rgb(%1, %2, %3)").arg(red).arg(green).arg(blue);
    qDebug() << "Farbe " << hexColour << " wurde zu " << rgbColour << "konvertiert.\n";
    return rgbColour;
}
