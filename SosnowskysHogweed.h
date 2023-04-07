#pragma once
#include "Plant.h"
#define LETTER_OF_SOSNOWSKYS_HOGWEED 'h'
#define NAME_OF_SOSNOWSKYS_HOGWEED "sosnowskys hogweed"
#define STRENGTH_OF_SOSNOWSKYS_HOGWEED 10
#define INITIATIVE_OF_SOSNOWSKYS_HOGWEED 0

class SosnowskysHogweed : public Plant
{
public:
	SosnowskysHogweed(World* world);
	SosnowskysHogweed(int coordinateX, int coordinateY, World* world);
	~SosnowskysHogweed();
	void action(char whichDirection) override;
	void basicAction(char whichDirection);
	void actionForSosnowskysHogweed();
	void draw();
};
