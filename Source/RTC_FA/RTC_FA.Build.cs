// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RTC_FA : ModuleRules
{
	public RTC_FA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
