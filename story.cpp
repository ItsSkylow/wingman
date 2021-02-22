#include "story.h"
#include "ui_story.h"

Story::Story(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Story)
{
    ui->setupUi(this);
}

Story::~Story()
{
    delete ui;
}
