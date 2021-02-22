#ifndef STORY_H
#define STORY_H

#include <QMainWindow>

namespace Ui {
class Story;
}

class Story : public QMainWindow
{
    Q_OBJECT

public:
    explicit Story(QWidget *parent = 0);
    ~Story();

private:
    Ui::Story *ui;
};

#endif // STORY_H
