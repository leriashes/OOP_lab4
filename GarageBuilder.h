#pragma once
#include "Builder.h"
#include "Gate.h"
#include "NumberPlateScanner.h"
#include "GateFM.h"
#include "NumplateVoiceFactory.h"

class GarageBuilder :
    public Builder
{
public:
	GarageBuilder();
	void createRoom();
	void buildOpener();
	void buildReader();
	void buildSolver();
	~GarageBuilder();
};

