// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCh11, Log, All);

#define LOCTEXT_NAMESPACE "Chapter11Namespace"
#define FTEXT(x) LOCTEXT(x,x)

extern FName LoggerName;

void CreateLog(FName logName);

