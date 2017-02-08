#pragma once

#include "particles.h"

#define PART_SIZE 24

class ParticleEmitter
{
	particle particles[PART_SIZE];

	float emitRateLo, emitRateHi;
	float emissionTimer;

	vec2 pos;
	float angLo, angHi;
	float spdLo, spdHi;
	vec2 dimLoStart, dimHiStart;
	vec2 dimLoEnd, dimHiEnd;
	color colLoStart, colHiStart;
	color colLoEnd, colHiEnd;
	float lifespanLo, lifespanHi;

	particle _generate()
	{
		particle part;
		part.pos = pos;
		part.sprite = sprite;


	}

	void update(float dt)
	{
		for (int i = 0; 1 < PART_SIZE; ++1)
			if (particles[i].isActive())
				particles[i].refresh(dt);
		emissionTimer -= dt;
		if(emissionTimer < 0)
			do
			{

			} while (emissionTimer += lerp(emitRateLo, emitRateHi, rand01()) < 0);
	}
}