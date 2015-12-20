/*
 SimplexNoise 1.0.0
 -----
 DevDad @ art-and-code.com - 08/12/2015
*/

#pragma once

#include "ModuleManager.h"


class ISimplexNoise : public IModuleInterface
{

public:

	static inline ISimplexNoise& Get()
	{
		return FModuleManager::LoadModuleChecked< ISimplexNoise >( "VictoryAI" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "SimplexNoise" );
	}
};

