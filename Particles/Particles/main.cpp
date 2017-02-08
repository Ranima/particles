#include "sfwdraw.h"
#include "math.h"
#include <iostream>
#include "particleEmitter.h"

#include "objectPool.h"

void doSomthing(const particle *)
{

}

void main()
{
	sfw::initContext();

	unsigned sprite =
	sfw::loadTextureMap("");

	ParticleEmitter pe;

	pe.emitRateLo = 0.01f;
	pe.emitRateHi = 0.03f;

	pe.sprite = sprite;

	pe.pos = vec2{ 400, -200 };
	pe.angLo = 45;
	pe.angHi = 135;
	pe.spdLo = 120;
	pe.spdHi = 320;
	pe.dimLoStart = vec2{ 8,8 };
	pe.dimHiStart = vec2{ 32,32 };
	pe.dimLoEnd = vec2{ 256,256 };
	pe.dimHiEnd = vec2{ 512, 512 };

	pe.colLoStart.ui_color = WHITE;
	pe.colHiStart.ui_color = YELLOW;
	pe.colLoEnd.ui_color = BLUE;
	pe.colHiEnd.ui_color = RED;

	pe.lifespanLo = 3.5f;
	pe.lifespanHi = 5.7f;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		pe.update(dt);
	}

	sfw::termContext();
}