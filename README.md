*This project has been created as a part of 42 curriculum by diachoug, mgrager*

## DESCRIPTION
The aim of the project cub3D is to created a Wolfenstein like game using the raycasting method.
We have to implement, for the mandatory part :
- A raycasting with fish a fish-eye correction
- A player movement
- A camera movement
- A player that is spawning in the corresponding direction (N = north, S = south, e = east, W = west)
- Read the instruction directly on the .cub map file (NO = texture north, SO = texture south, EA = texture east, WE = texture west, F = floor colour, C = ceiling colour, the map itselft must be the seventh and last element)
- The red cross or ESC must close the program nicely
- A clear error message have to appear on the terminal in case the map is rejected

For the bonus part, we must add :
- Wall collision
- Animated sprite
- Mouse pointer moving the camera
- Doors that can open and close
- A minimap system

For this project, more features have been added. We are going to talk about ir below

## INSTRUCTIONS
In the root repository, make sure that the MiniLibX is present. The repository name must be "minilibx-linux".
For the mandatory part enter the command : 	Make
For the bonus part enter the commande : 	Make bonus
Then, launch the program ./cub3D with a map as argv[1].
Enjoy.

Characters allowed in the map : N, S, E, W (player), 0 (floor), 1 wall. Bonus : 2 (must be a 3*3 surrounded by 2 floor), 3 (must be a 7*7 surrounded by 3 floors), C (door closed - O door open isn't accepted at init).

## CONTROLS
Mandatory :
- W : 						Move up
- A : 						Move left
- S : 						Move back
- D : 						Move right
- Left array : 				Rotate camera left
- Right array : 			Rotate camera right
- ESC/rec cross :			Leave game

Bonus :
- P :						Turn on/off elecricity
- O :						Call ghosts
- I :						Scare ghosts
- Q :						Fast forward/hide message
- M :						Controls
- R :						Launch/relaunch the Mathix
- Y :						Blue pill
- T :						Red pill
- Up array/wheel up :		Zoom in
- Down array/wheel down :	Zoom out

## FEATURES
- A raycasting engine that differenciates the 4 faces, based on the one explained by lodev (see sources).
- A control menu (press m).
- A non blocking tutorial
- A generic, as the form of a crawl (Star Wars like)
- A Matrix (it's a surprise)

## RESOURCES
- https://lodev.org/cgtutor/raycasting.html Main ressource, used for all the raycasting part
- https://www.youtube.com/watch?v=F-Z3qLSLOOw Understand to understand whau is racasting
- https://www.youtube.com/watch?v=NbSee-XM7WA


## AI Usage
Per the subject instructions, strict guidelines regarding AI usage were followed.