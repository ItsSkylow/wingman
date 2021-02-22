#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <iostream>
#include <Mmsystem.h>
#include <mciapi.h>
#include <thread>
#include <future>         // std::async, std::future
//these two headers are already included in the <Windows.h> header
#include "story.h"
#pragma comment(lib, "winmm.lib")
using namespace std;


void playSound(){ //Ouvrir le son de la musique
    mciSendString(TEXT("open \"C:\\Users\\M2IHM\\Desktop\\ProjetSahri\\SoundEffect\\Intro Sahri.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
    mciSendString(TEXT("play mp3"), NULL, 0, NULL);
}

void stopSound(){ //Arreter le son de la musique
    mciSendString(TEXT("stop mp3"), NULL, 0, NULL);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    playSound();
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DebuterVoyage_clicked()
{
    this->close();
    Story *w = new Story();
    w->show();
    stopSound();

}
