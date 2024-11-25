#include "square.h"
#include <QPainter>
#include <QMouseEvent>
#include <iostream>

Square::Square(int x, int y, QWidget *parent)
    : QWidget(parent), x(x), y(y), piece(nullptr)
{
    setFixedSize(50, 50);
    setMouseTracking(true);
}

int Square::getX() const
{
    return x;
}

int Square::getY() const
{
    return y;
}

Piece* Square::getPiece() const
{
    return piece;
}

bool Square::getHighlighted() const
{
    return isHighLighted;
}

void Square::setPiece(Piece *newPiece)
{
    piece = newPiece;
    update();
}

void Square::setHighlighted(bool highlight)
{
    this->isHighLighted = highlight;
    update();
}

/*
void Square::highlightSetOfSquares(const std::vector<Square*> &squares, bool highlight)
{
    qDebug() << "SIZE: " << squares.size();
    qDebug()<< "Highlight: " << squares[0]->getHighlighted();

    if (squares[0] != nullptr) {
        qDebug() << "Here";
        squares[0]->setHighlighted(highlight);
    } else {
        qDebug() << "squares[0] is a null pointer.";
    }

    //for (Square* square : squares) {
     //   square->setHighlighted(highlight);
    //}
} */

void Square::highlightSetOfSquares(const std::vector<Square*>& squares, bool highlight)
{
    qDebug() << "SIZE: " << squares.size();

    if (!squares.empty() && squares[0] != nullptr) {
        qDebug() << "Highlight: " << squares[0]->getHighlighted();
        qDebug() << "Here";

        // Ensure squares[0] is valid
        squares[0]->setHighlighted(highlight);
    } else {
        qDebug() << "squares[0] is a null pointer or squares is empty.";
    }

    // Highlight all squares
    for (Square* square : squares) {
        if (square != nullptr) {
            square->setHighlighted(highlight);
        } else {
            qDebug() << "Encountered a null pointer in squares vector.";
        }
    }
}


//paintEvent can modify the appearance of chess pieces within each square
void Square::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    bool isWhiteSquare = ((x+y) % 2 == 0);
    QColor color = isWhiteSquare ? QColor(Qt::white) : QColor(Qt::gray);

    if(isHighLighted){
        color = QColor(Qt::yellow).lighter(150);
    }

    painter.fillRect(rect(), color);

    //Adding a border to squares
    //QColor pieceBorderColor = isWhiteSquare ? QColor(Qt::white) : QColor (Qt::black);
    //int borderWidth = 2;
    //QPen pen(pieceBorderColor, borderWidth);
    //painter.setPen(pen);
    //painter.drawRect(rect().adjusted(0, 0, -borderWidth, -borderWidth));

    if(piece) {
        QPixmap pixmap = piece->getPixmap();
        painter.drawPixmap(rect(), pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Square::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        emit squareClicked(x, y);
    }
}
