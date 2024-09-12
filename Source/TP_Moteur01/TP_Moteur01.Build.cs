// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP_Moteur01 : ModuleRules
{
	public TP_Moteur01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
