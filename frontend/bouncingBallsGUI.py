# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 10:59:47 2023

@author: Arvid
"""

import pygame
import random
import time

x_max = 700
y_max = 400
r_max = 20

def main():
    global running, screen
    pygame.init()    
    screen = pygame.display.set_mode((700, 400)) 
    pygame.display.set_caption("Bouncing Balls") 
    screen.fill((255, 255, 255))
    # drawCircle(300, 140, 10,)
    
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN: # Generate new circle
                                                        # on mouse click
                
                if event.button == 1: # Left
                    c = (0, 0, 255) # Blue
                elif event.button == 2: # Middle
                    c = (0,0,0) # Black
                elif event.button == 3: # Right
                    c = (255, 0, 0) # Red
                    
                r_new = random.uniform(0.2 * r_max, r_max)
                x_new = random.uniform(r_new, x_max)
                y_new = random.uniform(r_new, y_max)
                drawCircle(x_new, y_new, r_new, c)
                # time.sleep(0.5)
                pygame.display.update()
    pygame.quit()        
    
    
    
def drawCircle(x, y, r, c):
    pygame.draw.circle(screen, c, (x, y), radius=r)
    
if __name__ == "__main__":
    main()