#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <iostream>
#include <Mmsystem.h>
#include <mciapi.h>
#include <thread>
#include <future>         // std::async, std::future
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "winmm.lib")
using namespace std;


void playSound(){
    mciSendString(TEXT("open \"C:\\Users\\M2IHM\\Desktop\\ProjetSahri\\SoundEffect\\Intro Sahri.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
    mciSendString(TEXT("play mp3 wait"), NULL, 0, NULL);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //std::thread t1 (playSound);
    std::async (playSound);
    //t1.join();
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}
