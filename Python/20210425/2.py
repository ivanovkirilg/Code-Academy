class Entity:
    def __init__(self, name='Name'):
        self.name = name
    def log_obj(self):
        print('Entity named', self.name)

class Player(Entity):
    def log_obj(self):
        print('Player named', self.name)

Entity('Thing').log_obj()
Player('Jack').log_obj()
