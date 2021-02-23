#ifndef STORY_H
#define STORY_H

#include <QMainWindow>
#include <gestionhaptique.h>

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

private:
    Ui::Story *ui;
    GestionHaptique *mHaptique;
};

#endif // STORY_H
