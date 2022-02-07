#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QLabel>
#include <QString>
#include <stack>
#include <QRect>
#include <QGridLayout>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->shuffle, SIGNAL(clicked()), this, SLOT(on_shuffle_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_shuffle_clicked(){
    int no = 30;

    int in[9];
    int blank;
    for(int i=0; i<9; i++)
        in[i] = i+1;
    in[8] = 0;
    blank = 9;
    for(int i = 0; i<no; i++){
        switch(blank){
        case 1 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[0]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 1:
                in[0]=in[3];
                in[3]=0;
                blank = 4;
                break;
            default:
                break;
            }
            break;
        case 2 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[1]=in[0];
                in[0]=0;
                blank = 1;
                break;
            case 1:
                in[1]=in[2];
                in[2]=0;
                blank = 3;
                break;
            case 2:
                in[1]=in[4];
                in[4]=0;
                blank = 5;
                break;
            default:
                break;
            }
            break;
        case 3 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[2]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 1:
                in[2]=in[5];
                in[5]=0;
                blank = 6;
                break;
            default:
                break;
            }
            break;
        case 4 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[3]=in[0];
                in[0]=0;
                blank = 1;
                break;
            case 1:
                in[3]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[3]=in[6];
                in[6]=0;
                blank = 7;
                break;
            default:
                break;
            }
            break;
        case 5 :j = (int) ((float)rand()/RAND_MAX * 4);
            switch(j){
            case 0:
                in[4]=in[3];
                in[3]=0;
                blank = 4;
                break;
            case 1:
                in[4]=in[5];
                in[5]=0;
                blank = 6;
                break;
            case 2:
                in[4]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 3:
                in[4]=in[7];
                in[7]=0;
                blank = 8;
                break;
            default:
                break;
            }
            break;
        case 6 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[5]=in[2];
                in[2]=0;
                blank = 3;
                break;
            case 1:
                in[5]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[5]=in[8];
                in[8]=0;
                blank = 9;
                break;
            default:
                break;
            }
            break;
        case 7 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[6]=in[7];
                in[7]=0;
                blank = 8;
                break;
            case 1:
                in[6]=in[3];
                in[3]=0;
                blank = 4;
                break;
            }
            break;
        case 8 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[7]=in[6];
                in[6]=0;
                blank = 7;
                break;
            case 1:
                in[7]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[7]=in[8];
                in[8]=0;
                blank = 9;
                break;
            default:
                break;
            }
            break;
        case 9 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[8]=in[7];
                in[7]=0;
                blank = 8;
                break;
            case 1:
                in[8]=in[5];
                in[5]=0;
                blank = 6;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    QString s="";
    for (int i=0;i<9;i++){
        s = s + QString :: number(in[i]) + " ";
    }
}
