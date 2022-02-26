#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum pieceType { Rook = 'r', Knight = 'n', Bishop = 'b', Queen = 'q', King = 'k', Pawn ='p', Empty = ' ' };
enum pieceColor { White = 'w', Black = 'b' };

struct boardElement {
    pieceType piece;
    pieceColor color;
    QGraphicsPixmapItem *icon;
    int xPos;
    int yPos;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QVector<QGraphicsPixmapItem*> whiteFigures;
    QVector<QGraphicsPixmapItem*> blackFigures;

    boardElement board[8][8];

public:

    void initBoard(QString fen);
    void drawBoard();
    void drawFigure(boardElement);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *figure;

};
#endif // MAINWINDOW_H
