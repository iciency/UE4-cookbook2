// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_04GameModeBase.h"
#include "InventoryCharacter.h"

AChapter_04GameModeBase::AChapter_04GameModeBase()
{
	DefaultPawnClass = AInventoryCharacter::StaticClass();
}

 