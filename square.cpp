#include "square.h"
#include <QPainter>
#include <QMouseEvent>

Square::Square(int x, int y, QWidget *parent)
    : QWidget(parent), x(x), y(y), piece(nullptr)
{
    setFixedSize(50, 50);
    setMouseTracking(true);
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

Piece* Square::getPiece() const {
    return piece;
}

void Square::setPiece(Piece *newPiece) {
    piece = newPiece;
    update();
}

//paintEvent can modify the appearance of chess pieces within each square
void Square::paintEvent(QPaintEvent *event) {
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

void Square::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        emit squareClicked(x, y);
    }
}
