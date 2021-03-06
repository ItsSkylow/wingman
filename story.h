#ifndef STORY_H
#define STORY_H

#include <QMainWindow>
#include <gestionhaptique.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <QFile>
#include <string>
#include <QtMultimedia/QSound>
#include <thread>
#include <QSoundEffect>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QFontDatabase>
#include <QThread>
#include <QTimer>
#include <QDebug>

typedef void (Story::*ScriptFunction)(void); // function pointer type

namespace Ui {
class Story;
}

class Story : public QMainWindow
{
    Q_OBJECT

public:
    explicit Story(QWidget *parent = 0);

    ~Story();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void displayText(const char* chaine);
    void firstScene();
    void secondScene();
    void thirdScene();
    void fourthScene();
    void fifthScene();
    QTimer* createTimer(double nb, const char* toDisplay );
    QTimer* createTimer(double nb, const char* toDisplay,CImmCompoundEffect * effect );
    QTimer* createTimer(double nb, const char* toDisplay, bool addToMapTimer );
    QTimer* createTimer(double nb, const char* toDisplay, CImmCompoundEffect * effect, bool addToMapTimer );
    void clearMapTimer();

    void on_spinPage_editingFinished();

    void on_spinPage_valueChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    double delayPrintText = 7000.;
    Ui::Story *ui;
    GestionHaptique *mHaptique;
    std::map<int, QTimer*> mapTimer;
    std::map<int, ScriptFunction> mapStory;
    std::map<int, const char*> mapSoundScene;
    int currentPage = 0;
    int maxLabelInCurrentScene = 0;

    void initSounds();
    void playSound(int id);
    void stopSound(int id);
    void pauseSound(int id);
    void resumeSound(int id);
    void playSoundFromBegin(int id);
    void stopAllSound();

    QSoundEffect *sound;
    bool soundOn = true;
    DWORD dwVolume;
    bool isPlaying = false;
    int lastSceneId = 0;
};

#endif // STORY_H
