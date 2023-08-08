// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Chapter_13 : ModuleRules
{
	public Chapter_13(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
		PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "GameplayTasks" });
	}
}
