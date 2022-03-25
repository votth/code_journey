# https://www.learnpython.org/en/Modules_and_Packages


print("Module is a piece of software that has a specific functionality.")

print("In Python, modules are just files with .py extension, name of module = name of file. It has a set of functions, classes or variables defined and implemented.")

# example game modules
# the following belongs to a game.py file

import draw

def play_game():
    ...

def main():
    result = play_game()
    draw.draw_game(result)

# this means that if this script is executed, then main() will be excecuted
if __name__ == '__main__':
    main()


# the following belong to a draw.py file
def draw_game():
    ...

def clear_screen(screen):
    ...


# another way to import function from modules

from draw import draw_game
# from draw import *
# to import every objects from `draw` module

def main():
    result = play_game()
    draw_game(result) # this time only the function name is needed since we've already specified with the `from` `import`




# game.py
# import the draw module
if visual_mode:
    # in visual mode, we draw using graphics
    import draw_visual as draw
else:
    # in textual mode, we print out text
    import draw_textual as draw

def main():
    result = play_game()
    # this can either be visual or textual depending on visual_mode
    draw.draw_game(result)
