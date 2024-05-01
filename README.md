# VirtualWorld C++
# Overview
A simple console game in which you steer a human in a world full of animals and plants. All organisms have strength and initiative. Strength determines which organism wins when they collide and initiative which determines the order in which organisms make their moves (in animals age is also a factor in the order). The game has the option to save gamestate to file or to start a game from an existing file.
## Animals you can encounter:
- Wolf
- Sheep
- Antilope (can move 2 tiles at once and has 50% chance to run away from the attacker)
- Fox (will never attack a stronger opponent)
- Turtle (will not be killed by an attacker with strength lower than 5)
## Plants you can encounter:
- Dandelion
- Grass
- Guarana (Increases strength by 3)
- Pine Borscht (kills in proximity)
- Wolf Berries (kills after being eaten)
## Human
Player has an option to press Q which activates immortality for a certain amount of rounds. After it expires, some time is needed for the power to recover.
T saves the game and Y lets you load a game from a file.
## Signs 
- Wolf: W
- Sheep: S
- Fox: F
- Turtle: T
- Antylope: A
- Human: H
- Grass: #
- Dandelion: @
- Guarana: +
- Wolf Berries: -
- Pine Borscht: !
