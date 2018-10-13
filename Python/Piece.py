
class Piece:

    def __init__(self, team = "EMPTY", name = "EMPTY"):
        self.team = team
        self.name = name
    
    def setTeam(self, newTeam):
        self.team = newTeam 
    
    def setType(self, newName):
        self.name = newName
    
    def isBlack(self):
        return self.team == "BLACK"
    
    def isWhite(self):
        return self.team == "WHITE"
    
    def isBlank(self):
        return self.team == "EMPTY"
    
    def isKnite(self):
        return self.name == "KNIGHT"
    
    def getName(self):
        return self.name




