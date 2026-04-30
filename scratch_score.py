import os
import sys
import numpy as np

sys.path.insert(0, '/Users/feng/Downloads/work/Pybert')

from state import InnerGameState
import json

def test():
    with open('/Users/feng/Downloads/work/Pybert/games/uNEkilA93v9VF2Ic_W1902A.json', 'r') as f:
        game_data = json.load(f)
        
    class MockGame:
        def __init__(self, d):
            self.map = type('obj', (object,), {'homes': d['state']['homes']})
            self.state = type('obj', (object,), {'units': d['state']['units'], 'centers': d['state']['centers'], 'name': d['name']})
            self.rules = d['rules']
            self.sc_count = {p: len(c) for p, c in d['state']['centers'].items()}
            self.order_history = []
    game = MockGame(game_data)
    # The actual inner state needs more than just this to synchronize, but maybe we can just load the state directly
    print("Test ready")

if __name__ == '__main__':
    test()
