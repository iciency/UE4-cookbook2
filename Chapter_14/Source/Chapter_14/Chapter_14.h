// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CookbookStyle.h"

class Chapter_14Module : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		FCookbookStyle::Initialize();
	};
	virtual void ShutdownModule() override
	{
		FCookbookStyle::Shutdown();	
	};
};
