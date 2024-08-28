# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 10:59:47 2023

@author: Arvid
"""

import pygame

pygame.init()

# Colors
c_black = (0, 0, 0)
c_white = (255, 255, 255)
c_red = (255, 0, 0)
c_green = (0, 255, 0)
c_blue = (0, 0, 255)

def initGuiRect(width, height):
    global window
    window = pygame.display.set_mode((width, height))
    pygame.display.set_caption("Bouncing Balls")
    
def initGuiCirc(radius):
    global window
    global window_factor_to_radius
    window_factor_to_radius =2.1
    
    window = pygame.display.set_mode((window_factor_to_radius*radius, window_factor_to_radius*radius))
    pygame.display.set_caption("Bouncing Balls")
    
def drawWindowRect(x_vals, y_vals, r_vals):
    window.fill(c_white)
    
    for i in range(len(x_vals)):
        pygame.draw.circle(window, c_red, (int(x_vals[i]), int(y_vals[i])), int(r_vals[i]))
   
    pygame.display.flip()
    
def drawWindowCirc(x_vals, y_vals, r_vals, radius):
    window.fill(c_white)
       
    pygame.draw.circle(window, c_black, (window_factor_to_radius/2 * radius, window_factor_to_radius/2 * radius), radius, width=2)
    for i in range(len(x_vals)):
        pygame.draw.circle(window, c_red, (int(window_factor_to_radius/2 * radius + x_vals[i]), int(window_factor_to_radius/2 * radius + y_vals[i])), int(r_vals[i]))
   
    pygame.display.flip()