Assignment 1 - Maze Generation and Binary saving - Programming for C++.
The following assignment generates a maze of N*N dimensions based upon a random seed value, 
using the Aldous-Broder method. The application accepts a binary input file, and will output
the given maze to an SVG file. 
Authors: 
Luke Ellison - s3484756  - Lead developer aka Cthulhu apprentice.
Joshua Theeuf - s3234575 - 2nd developer.
Known issues:
	- The current application does not accept a maze with varying dimensions. Both height and width must be the same.
	- The current application does not completely generate a maze when the dimensions of the maze are 35> and the seed is 10<.
	- The current application does not generate a maze when the dimensions are small with respect to the seed value. 
how to compile:
	make clean.
	make.
	----
	profit??
how to run.
	./mazer (--lb)(--g)(seed)(--sb)(Binary File Name.maze))(--sv)(Svg File name .svg)
	
Git-repo:
	https://github.com/s3484756/c-project
	

	