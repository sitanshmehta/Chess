#include "board.h"
#include "square.h"
#include "rook.h"
#include <QGridLayout>
#include "iostream"


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

void Board::setupBoard()
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(0);
    //grid->setMargin(0);

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for(int col = 0; col < BOARD_SIZE; ++col) {
            squares[row][col] = new Square(col, row, this);
            grid->addWidget(squares[row][col], row, col);

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
                    // piece = new Knight(pieceColor);
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
                    // piece = new Pawn(pieceColor);
                    break;
                default:
                    break;
                }

                if(piece){
                    squares[row][col]->setPiece(piece);
                    piece->setCurrSquare(squares[row][col]);
                    //std::vector<Square*> valid = piece->getValidMoves(this);
                }
            }

        }
    }

    setLayout(grid);
}

Square* Board::getSquare(int row, int col) const {
    return this->squares[row][col];
}

void Board::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
