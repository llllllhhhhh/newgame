// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FightGame : ModuleRules
{
	public FightGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"BlueprintLibrary"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FightGame",
			"FightGame/Variant_Platforming",
			"FightGame/Variant_Platforming/Animation",
			"FightGame/Variant_Combat",
			"FightGame/Variant_Combat/AI",
			"FightGame/Variant_Combat/Animation",
			"FightGame/Variant_Combat/Gameplay",
			"FightGame/Variant_Combat/Interfaces",
			"FightGame/Variant_Combat/UI",
			"FightGame/Variant_SideScrolling",
			"FightGame/Variant_SideScrolling/AI",
			"FightGame/Variant_SideScrolling/Gameplay",
			"FightGame/Variant_SideScrolling/Interfaces",
			"FightGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
