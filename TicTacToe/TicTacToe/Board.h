#pragma once

//What is the board?
//	3X3 grid

class board
{
private:
	struct vec2 {
		float x, y;
	};

	vec2 Gpos[9];
	int Gtyp[9];		//the grid

public:
	void init();	//set
	void update();
	void draw();	//draw everthing
};