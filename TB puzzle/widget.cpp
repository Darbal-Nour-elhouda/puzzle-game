#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>
#include <iostream>
#include <QPixmap>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>

#define WIDTH_SIZE 105
#define HEIGHT_SIZE 115

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_board = NULL;
    m_puzzle_widget = NULL;
    m_goal = NULL;

    connect_slots();
    setup_board();

    QPixmap title(":/Images/Title Black.png");
    ui->Title->setPixmap(title);

    QWidget::setWindowTitle("TB Puzzle");
    setWindowIcon(QIcon(":/Images/Icon.png"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_HTPbtn_clicked()
{
     QMessageBox *tutorial = new QMessageBox;

     tutorial->setWindowIcon(QIcon(":/Images/Messaging-Question-icon.png"));
     tutorial->setWindowTitle("How to play");
     tutorial -> setText("Choose which picture you want to play then select your choice of level.\nTo start the game, click 'Scramble'");
     tutorial -> show();
}

void Widget::on_ExitBtn_clicked()
{
    QMessageBox msgBox;

    msgBox.setWindowIcon(QIcon(":/Images/Icon.png"));
    msgBox.setWindowTitle("TB Puzzle");
    msgBox.setText("Are you sure you want to exit?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes)
    {
        QApplication::exit();
    }

}

void Widget::on_StartBtn_clicked()
{
    int index = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentIndex(index + 1);
}

void Widget::on_back_clicked()
{
    int index = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentIndex(index - 1);
}

void Widget::connect_slots(){
    connect(ui->scramble_pushButton,SIGNAL(clicked()),this,SLOT(scramble()));
    connect(ui->size_spinBox,SIGNAL(valueChanged(int)),this,SLOT(setup_board()));
    connect(ui->reset_pushButton,SIGNAL(clicked()),this,SLOT(reset()));
}

void Widget::setup_board(){

    int width_constant = WIDTH_SIZE;
    int height_constant = HEIGHT_SIZE;
    int size = ui->size_spinBox->value();

    if(m_board != NULL)
        delete m_board;
    if(m_goal != NULL)
        delete m_goal;
    if(m_puzzle_widget != NULL)
        delete m_puzzle_widget;

    m_board = new PuzzleBoard(size);
    m_goal = new PuzzleBoard(size);
    m_puzzle_widget = new BoardWidget(m_board,false,ui->comboBox->currentIndex(),ui->puzzle_dock_widget);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),m_puzzle_widget,SLOT(change_image(int)));

    ui->puzzle_dock_widget->setWidget(m_puzzle_widget);
    ui->puzzle_dock_widget->resize(size*width_constant,size*height_constant);
    ui->puzzle_dock_widget->setMinimumWidth(size*width_constant);
    ui->puzzle_dock_widget->setMinimumHeight(size*height_constant);
    ui->puzzle_dock_widget->setMaximumWidth(size*width_constant);
    ui->puzzle_dock_widget->setMaximumHeight(size*height_constant);

    int currentpic = ui->comboBox->currentIndex();
    int h = ui->solution_pic->height();
    int w = ui->solution_pic->width();

    QPixmap pix0 (":/Images/awesome3x3.jpg");
    QPixmap pix1 (":/Images/troll_face3x3.png");
    QPixmap pix2 (":/Images/rage3x3.jpg");
    QPixmap pix3 (":/Images/classic4x4.png");
    QPixmap pix4 (":/Images/gray4x4.png");
    QPixmap pix5 (":/Images/red4x4.jpg");
    QPixmap pix6 (":/Images/orange4x4.png");
    QPixmap pix7 (":/Images/rupp4x4.png");
    QPixmap pix8 (":/Images/ited4x4.png");
    QPixmap pix9 (":/Images/tb4x4.png");
    QPixmap pix10 (":/Images/me4x4.png");


    switch (currentpic) {
        case 0:
            ui->solution_pic->setPixmap(pix0.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 1:
            ui->solution_pic->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 2:
            ui->solution_pic->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 3:
            ui->solution_pic->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 4:
            ui->solution_pic->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 5:
            ui->solution_pic->setPixmap(pix5.scaled(w,h,Qt::KeepAspectRatio));
        break;

        case 6:
            ui->solution_pic->setPixmap(pix6.scaled(w,h,Qt::KeepAspectRatio));
        break;
    case 7:
        ui->solution_pic->setPixmap(pix7.scaled(w,h,Qt::KeepAspectRatio));
    break;
    case 8:
        ui->solution_pic->setPixmap(pix8.scaled(w,h,Qt::KeepAspectRatio));
    break;
    case 9:
        ui->solution_pic->setPixmap(pix9.scaled(w,h,Qt::KeepAspectRatio));
    break;
    case 10:
        ui->solution_pic->setPixmap(pix10.scaled(w,h,Qt::KeepAspectRatio));
    break;

    }

}

void Widget::reset(){

    ui->size_spinBox->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->scramble_pushButton->setEnabled(true);
    setup_board();
    m_puzzle_widget->lock_board(false);

}

void Widget::start(){

    ui->size_spinBox->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->scramble_pushButton->setEnabled(false);
    ui->reset_pushButton->setEnabled(false);
    m_puzzle_widget->lock_board(true);

}

void Widget::scramble(){

    m_board->scramble_board_with_moves();
    m_puzzle_widget->set_curr_board(this->m_board);

}

void Widget::on_backfromselectpic_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(index-1);
}

void Widget::on_nexttogame_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(index+1);
    reset();
}
