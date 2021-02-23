#include "story.h"
#include "ui_story.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QFontDatabase>
#include <QThread>
#include <QTimer>

Story::Story(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Story)
{
    //Setup de l interface -- doit etre au debut
    ui->setupUi(this);

    //Initialisation de l haptique
    this->mHaptique = new GestionHaptique(this);

    //Ajout de la police specifique
    QFontDatabase::addApplicationFont(":/fonts/Font/AlfredDrake.ttf");
    QFont font = QFont("AlfredDrake",20,10);
    ui->storyLabel->setFont(font);
    ui->storyLabel->setStyleSheet("color: white; background-color: rgba(0,0,0,0.8)");
    ui->storyLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ui->storyLabel->setWordWrap(true);

    //Lancement de la firstScene
    this->firstScene();

}

Story::~Story()
{
    delete ui;
    if (mHaptique)
        delete mHaptique;
}


/*
 * Fonction pour l affichage du texte avec un effet de fade in
 * */
void Story::displayText(const char* chaine){
    //Effet d'apparition
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->storyLabel->setGraphicsEffect(eff);
    ui->storyLabel->setText(chaine);
    ui->storyLabel->adjustSize();
    ui->storyLabel->setAlignment(Qt::AlignCenter);
    QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
    a->setDuration(3000);
    a->setStartValue(0);
    a->setEndValue(1);
    a->start();




}

void Story::on_pushButton_clicked() //Bouton Retour
{


    this->firstScene();

}


void Story::on_pushButton_2_clicked() //Bouton suivant
{

}


void Story::firstScene(){
    this->centralWidget()->setStyleSheet("QWidget#storyBackground {background-image: url(':images/Images/desert.png')}");
    this->displayText("Il etait une fois, dans une contree eloigne, a une epoque que le temps a effacer de la memoire des hommes...");

    this->createTimer(1,"un jeune garçon du nom de Sahri.");
    this->createTimer(2,"Nul ne savait d’ou il venait ni qui il avait pour parents.");
    this->createTimer(3,"Certains racontait même qu’il était le fils des étoiles et de la lune.");
}

void Story::secondScene(){

}

QTimer* Story::createTimer(double nb,const char* toDisplay ){
    QTimer *m_myLongTimer = new QTimer(this);
    m_myLongTimer->setInterval(this->delayPrintText * nb);
    m_myLongTimer->setSingleShot(true);
    connect(m_myLongTimer, &QTimer::timeout, [this,toDisplay] {
       this->displayText(toDisplay);
    });
    m_myLongTimer->start();
    return m_myLongTimer;
}
