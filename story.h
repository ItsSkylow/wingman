#ifndef STORY_H
#define STORY_H

#include <QMainWindow>
#include <gestionhaptique.h>
#include <windows.h>

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
    QTimer* createTimer(double nb,const char* toDisplay );

private:
    double delayPrintText = 7000.;
    Ui::Story *ui;
    GestionHaptique *mHaptique;
};

#endif // STORY_H
