#pragma once
class Can
{
public:
	Can();
	int Hit(const int &thr); //checks what happens with the hit can. 0 - nothing, 1 - can falls near, 2 - can falls far
	int PutBack(); //puts can to the standing position

private:
	int state; //current state of the can. 0 - standing, 1 - laying near, 2 - laying far
};

