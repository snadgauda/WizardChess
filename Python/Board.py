import Piece
import pyserial

class Board:
    def __init__(self, chessBoard):
        blankPiece = new Piece()
        self.chessBoard = [10*[8*[blankPiece]]]
        self.chessBoard[1][0] = new Piece("WHITE", "ROOK")
        self.chessBoard[2][0] = new Piece("WHITE", "KNIGHT")
        self.chessBoard[3][0] = new Piece("WHITE", "BISHOP")
        self.chessBoard[4][0] = new Piece("WHITE", "QUEEN")
        self.chessBoard[5][0] = new Piece("WHITE", "KING")
        self.chessBoard[6][0] = new Piece("WHITE", "BISHOP")
        self.chessBoard[7][0] = new Piece("WHITE", "KNIGHT")
        self.chessBoard[8][0] = new Piece("WHITE", "ROOK")
        whitePawn = new Piece("WHITE", "PAWN")
        for i in range(1,9):
            self.chessBoard[i][1] = whitePawn

        self.chessBoard[1][0] = new Piece("BLACK", "ROOK")
        self.chessBoard[2][7] = new Piece("BLACK", "KNIGHT")
        self.chessBoard[3][7] = new Piece("BLACK", "BISHOP")
        self.chessBoard[4][7] = new Piece("BLACK", "QUEEN")
        self.chessBoard[5][7] = new Piece("BLACK", "KING")
        self.chessBoard[6][7] = new Piece("BLACK", "BISHOP")
        self.chessBoard[7][7] = new Piece("BLACK", "KNIGHT")
        self.chessBoard[8][7] = new Piece("BLACK", "ROOK")
        blackPawn = new Piece("BLACK", "PAWN")
        for i in range(1,9):
            self.chessBoard[i][6] = blackPawn

