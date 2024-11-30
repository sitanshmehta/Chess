#include "square.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <iostream>

Square::Square(int x, int y, QWidget *parent)
    : QWidget(parent),
      x(x),
      y(y),
      piece(nullptr),
      pressAndHoldTimer(new QTimer(this))
{
    pressAndHoldTimer->setSingleShot(true);
    connect(pressAndHoldTimer, &QTimer::timeout, this, [this]() {
        emit squareHeld(this->x, this->y);
    });

    setFixedSize(50, 50);
    setMouseTracking(true);
}

Square::~Square()
{
    //delete this;
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
    isHighLighted = highlight;
    update();
}

void Square::highlightSetOfSquares(const std::vector<Square*>& squares, bool highlight)
{

    if (!squares.empty() && squares[0] != nullptr) {
        // Ensure squares[0] is valid
        squares[0]->setHighlighted(highlight);
    }

    for (Square* square : squares) {
        if (square != nullptr) {
            square->setHighlighted(highlight);
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

    if(piece) {
        QPixmap pixmap = piece->getPixmap();
        painter.drawPixmap(rect(), pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Square::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        pressAndHoldTimer->start(500);
    }
}

void Square::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (pressAndHoldTimer->isActive()) {
            pressAndHoldTimer->stop();
            emit squareClicked(x, y);
        }
    }
}
