#include "story.h"
#include "ui_story.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QFontDatabase>

Story::Story(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Story)
{
    //Setup de l interface -- doit etre au debut
    ui->setupUi(this);

    //Initialisation de l haptique
    this->mHaptique = new GestionHaptique(this);

    //Ajout de la police specifique
    QFontDatabase::addApplicationFont(":/fonts/Font/kareem_mubarak/KareemMubarak.ttf");
    QFont font = QFont("KareemMubarak-DEMO",20,10);
    ui->storyLabel->setFont(font);



}

Story::~Story()
{
    delete ui;
    if (mHaptique)
        delete mHaptique;
}

void Story::on_pushButton_clicked() //Bouton Retour
{
    this->centralWidget()->setStyleSheet("QWidget#storyBackground {background-image: url(':images/Images/CitySahri.jpg')}");
    this->displayText("Il y a longtemps dans une galaxie lointaine tres lointaine");



}

/*
 * Fonction pour l affichage du texte avec un effet de fade in
 * */
void Story::displayText(const char* chaine){
    //Effet d'apparition
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->storyLabel->setGraphicsEffect(eff);
    ui->storyLabel->setText(chaine);
    QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
    a->setDuration(3000);
    a->setStartValue(0);
    a->setEndValue(1);
    a->start();
}

void Story::on_pushButton_2_clicked() //Bouton suivant
{

}
