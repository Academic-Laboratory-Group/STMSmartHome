#ifndef _PROG_H_
#define _PROG_H_

class Prog
{
	private:
		Prog();
		~Prog();
	
	
	
	public:
		void update(float deltaTime);
		void render();
		void processInput();
}	;

#endif
