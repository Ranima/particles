#pragma once

#include "particles.h"
#include "objectPool.h"

#define PART_SIZE 10000

class ParticleEmitter
{
	ObjectPool particles;

	void emit()
	{
		particles.push(_generate());
	}

	particle _generate()
	{
		particle part;
		part.pos = pos;
		part.sprite = sprite;

		part.vel = randDir(angLo, angHi) * lerp(spdLo, spdHi, rand01());

		part.lifespan = lerp(lifespanLo, lifespanHi, rand01());

		part.sColor = lerp(colLoStart, colHiStart, rand01());
		part.eColor = lerp(colLoEnd, colHiEnd, rand01());

		part.sDim = randRange(dimLoStart, dimHiStart);
		part.eDim = randRange(dimLoEnd, dimHiEnd);

		part.lifetime = 0;
		return part;
	}

	float emissionTimer;

public:

	float emitRateLo, emitRateHi;

	vec2 pos;
	unsigned sprite;
	float angLo, angHi;
	float spdLo, spdHi;
	vec2 dimLoStart, dimHiStart;
	vec2 dimLoEnd, dimHiEnd;
	color colLoStart, colHiStart;
	color colLoEnd, colHiEnd;
	float lifespanLo, lifespanHi;

	

	void update(float dt)
	{
		for (auto it = particles.begin(); it != particles.end(); )
		{
			it->refresh(dt);

			if (it->isActive())
				++it;
			else
				it.free();
		}

		emissionTimer -= dt;
		while (emissionTimer < 0)
		{
			emit();
			emissionTimer += lerp(emitRateLo, emitRateHi, rand01());
		}
	}
};