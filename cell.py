from enum import Enum


class CellState(Enum):
    OPENED = 1
    MARKED = 2
    CLOSED = 3

class Cell:

    def __init__(self, x : int , y : int) -> None:
        self.x = x
        self.y = y
        self.state = CellState.CLOSED
    
    #TODO
    """
        open method check if we can open the cell or not.
        if we can change the state to OPENED
        
        a cell can be opened if it's not marked or 
    """
    def open(self) -> None:
        return
    
    #TODO    
    """
        if cell is opened ignore, change state from OPENED to MARKED and vice versa.
    """
    def flip_mark(self):
        return
    