#include "square.h"
#include <QPainter>

Square::Square(int x, int y, QWidget *parent)
    : QWidget(parent), x(x), y(y), piece(nullptr)
{
    setFixedSize(50, 50);
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

void Square::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    QColor color = ((x+y) % 2 == 0) ? QColor(Qt::white) : QColor(Qt::gray);
    painter.fillRect(rect(), color);

    if(piece) {
        QPixmap pixmap = piece->getPixmap();
        painter.drawPixmap(rect(), pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
