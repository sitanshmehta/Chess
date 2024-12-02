#include "board.h"
#include "square.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include <QGridLayout>
#include "iostream"
#include <QDebug>

const std::string initialSetup[BOARD_SIZE][BOARD_SIZE] = {
    { "bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR" },
    { "bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP" },
    { "",   "",   "",   "",   "",   "",   "",   ""   },
    { "",   "",   "",   "",   "",   "",   "",   ""   },
    { "",   "",   "",   "",   "",   "",   "",   ""   },
    { "",   "",   "",   "",   "",   "",   "",   ""   },
    { "wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP" },
    { "wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR" }
};

Board::Board(QWidget *parent)
    : QWidget(parent)
{
    setupBoard();
}

Board::~Board()
{
    for(int row = 0; row < BOARD_SIZE; ++row) {
        for(int col = 0; col < BOARD_SIZE; ++col) {
            delete squares[row][col];
        }
    }
}

void Board::setSelectedPiece(Piece* piece)
{
    if(piece != nullptr){
        this->selectedPiece = piece;
    }
}

Square* Board::getSquare(int row, int col) const {
    if(row >=0 && row < BOARD_SIZE && col >=0 && col < BOARD_SIZE) {
        return this->squares[row][col];
    }
    return nullptr;
}

void Board::setupBoard()
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(0);

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for(int col = 0; col < BOARD_SIZE; ++col) {
            squares[row][col] = new Square(col, row, this);
            grid->addWidget(squares[row][col], row, col);

            //connecting squares signal to board's slot
            connect(squares[row][col], &Square::squareClicked, this, &Board::handleSquareClicked);
            connect(squares[row][col], &Square::squareHeld, this, &Board::handleSquarePressAndHold);
            std::string pieceCode = initialSetup[row][col];
            //If it isnt an empty square
            if(!pieceCode.empty()){
                //std::cout<< "CODE: " << pieceCode << std::endl;
                Piece::Color pieceColor = (pieceCode[0] == 'w') ? Piece::WHITE : Piece::BLACK;
                char pieceType = pieceCode[1];
                Piece* piece = nullptr;

                switch (pieceType) {
                    case 'R':
                        piece = new Rook(pieceColor);
                        break;
                    case 'N':
                        piece = new Knight(pieceColor);
                        break;
                    case 'B':
                        // piece = new Bishop(pieceColor);
                        break;
                    case 'Q':
                        // piece = new Queen(pieceColor);
                        break;
                    case 'K':
                        // piece = new King(pieceColor);
                        break;
                    case 'P':
                        piece = new Pawn(pieceColor);
                        break;
                    default:
                        break;
                }

                if(piece){
                    squares[row][col]->setPiece(piece);
                    piece->setCurrSquare(squares[row][col]);
                }
            }

        }
    }

    setLayout(grid);
}


void Board::handleSquarePressAndHold(int x, int y)
{
    Square* clickedSquare = getSquare(y, x);
    Piece* pieceOnSquare = clickedSquare->getPiece();
    bool addHighlight = true;

    bool isHighlighted = clickedSquare->getHighlighted();

    if(!isHighlighted) {
        clickedSquare->setHighlighted(true);
    }
    else {
        clickedSquare->setHighlighted(false);
        addHighlight = false;
    }

    if(pieceOnSquare != nullptr) {
        std::vector<Square*> validMoves = pieceOnSquare->getValidMoves(*this);
        Square::highlightSetOfSquares(validMoves, addHighlight);
    }
}

void Board::handleSquareClicked(int x, int y)
{
    Square* clickedSquare = getSquare(y, x);
    Piece* pieceOnSquare = clickedSquare->getPiece();

    if(this->selectedPiece != nullptr && isSquareOnBoard(clickedSquare)){
        std::vector<Square*> validMoves = this->selectedPiece->getValidMoves(*this);
        if(isSquareInValidMoves(validMoves, clickedSquare))
        {
            this->selectedPiece->moveToSquare(clickedSquare);
        }
        this->selectedPiece = nullptr;
    }

    if(pieceOnSquare != nullptr && this->selectedPiece == nullptr){
        this->selectedPiece = pieceOnSquare;
    }
}

bool Board::isSquareOnBoard(Square* square) const
{
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (squares[row][col] == square) {
                return true;
            }
        }
    }
    return false;
}


void Board::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

bool Board::isSquareInValidMoves(std::vector<Square*> validMoves, Square *square)
{
    return std::find(validMoves.begin(), validMoves.end(), square) != validMoves.end();
}
