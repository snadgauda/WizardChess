import Piece
import serial

class Board:
    def __init__(self):
        blankPiece =  Piece.Piece()
        self.chessBoard = [10*[8*[blankPiece]]]
        self.chessBoard[1][0] =  Piece.Piece("WHITE", "ROOK")
        self.chessBoard[2][0] =  Piece.Piece("WHITE", "KNIGHT")
        self.chessBoard[3][0] =  Piece.Piece("WHITE", "BISHOP")
        self.chessBoard[4][0] =  Piece.Piece("WHITE", "QUEEN")
        self.chessBoard[5][0] =  Piece.Piece("WHITE", "KING")
        self.chessBoard[6][0] =  Piece.Piece("WHITE", "BISHOP")
        self.chessBoard[7][0] =  Piece.Piece("WHITE", "KNIGHT")
        self.chessBoard[8][0] =  Piece.Piece("WHITE", "ROOK")
        whitePawn =  Piece.Piece("WHITE", "PAWN")
        for i in range(1,9):
            self.chessBoard[i][1] = whitePawn

        self.chessBoard[1][0] =  Piece.Piece("BLACK", "ROOK")
        self.chessBoard[2][7] =  Piece.Piece("BLACK", "KNIGHT")
        self.chessBoard[3][7] =  Piece.Piece("BLACK", "BISHOP")
        self.chessBoard[4][7] =  Piece.Piece("BLACK", "QUEEN")
        self.chessBoard[5][7] =  Piece.Piece("BLACK", "KING")
        self.chessBoard[6][7] =  Piece.Piece("BLACK", "BISHOP")
        self.chessBoard[7][7] =  Piece.Piece("BLACK", "KNIGHT")
        self.chessBoard[8][7] =  Piece.Piece("BLACK", "ROOK")
        blackPawn =  Piece.Piece("BLACK", "PAWN")
        for i in range(1,9):
            self.chessBoard[i][6] = blackPawn

    def movePiece(self, oldX, oldY, newX, newY):
        if not self.chessBoard[newX][newY].isBlank():
            pass # move to queue

        if self.chessBoard[oldX][oldY].isKnight():
            pass # call the move knight method
        else:
            pass # just straight up move da piece.
