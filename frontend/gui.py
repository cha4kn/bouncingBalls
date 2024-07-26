# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 10:59:47 2023

@author: Arvid
"""

import pygame

pygame.init()

# Colors
c_white = (255, 255, 255)
c_red = (255, 0, 0)
c_green = (0, 255, 0)
c_blue = (0, 0, 255)

def initGui(width, height):
    global window
    window = pygame.display.set_mode((width, height))
    pygame.display.set_caption("Bouncing Balls")    
    
def drawWindow(x_vals, y_vals, r_vals):
    window.fill(c_white)
    
    for i in range(len(x_vals)):
        pygame.draw.circle(window, c_red, (int(x_vals[i]), int(y_vals[i])), int(r_vals[i]))
   
    pygame.display.flip()