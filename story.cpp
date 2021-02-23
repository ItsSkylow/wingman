#include "story.h"
#include "ui_story.h"
#include <QPropertyAnimation>

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

void Story::on_pushButton_clicked()
{
    this->centralWidget()->setStyleSheet("QWidget#storyBackground {background-image: url(':images/Images/CitySahri.jpg')}");
}

void Story::on_pushButton_2_clicked()
{

}
