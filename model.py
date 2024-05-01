from enum import Enum
from cell import Cell

class GameStatus(Enum):
    WIN=1
    LOSE=2
    RUNNING=3

class Model:
    board = [[]]
    MAX_HEIGHT=0
    MAX_WIDTH=0
    MINES_NUMBER=0

    def __init__(self):
        pass

    def new_game(self)->None:
        pass
    '''
        make a game with max height = 8 , max weidth = 8 , mines = 10
    '''
    def make_easy_game(self)->None:
        pass
    '''
        make a game with max height = 10 , max weidth = 10 , mines = 15
    '''
    def make_medium_game(self)->None:
        pass
    '''
        make a game with max height = 12 , max weidth = 12 , mines = 25
    '''
    def make_hard_game(self)->None:
        pass
    '''
        return game status
    '''
    def get_game_status(self)->GameStatus:
        pass
    '''
        initialize the board matrix with objects of type cells.
        choose random cells to contain mines
    '''
    def create_board(self)->None:
        pass
    '''
        get cell at board[x][y]
    '''
    def get_cell(self, x:int, y:int)->Cell:
        pass
    '''
        try open the cell , if it can be opened traverse to all neighbours 
        which don't contain a mine and open them.
    '''
    def open_cell(self)->None:
        pass