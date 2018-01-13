#include"staticfun.h"

static vector<demoStru>&
GetDemoVec()
{
	static vector<demoStru>* vp = new vector<demoStru>();

	return *vp;
}