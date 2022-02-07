#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "puzzle_board.h"
#include "board_widget.h"
#include <QTimer>
#include <QTime>
#include <QListWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget();

public slots:

    void start();
    void scramble();
    void setup_board();
    void reset();

    void on_HTPbtn_clicked();

    void on_StartBtn_clicked();

    void on_ExitBtn_clicked();

    void on_back_clicked();

private slots:
    void on_backfromselectpic_clicked();

    void on_nexttogame_clicked();

private:

    void connect_slots();
    Ui::Widget *ui;
    BoardWidget *m_puzzle_widget;
    PuzzleBoard *m_board;
    PuzzleBoard *m_goal;
};

#endif // WIDGET_H
