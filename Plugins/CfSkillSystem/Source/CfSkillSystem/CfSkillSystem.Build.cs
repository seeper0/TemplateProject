// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CfSkillSystem : ModuleRules
{
	public CfSkillSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
		);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
				"EnhancedInput",
				"GameplayTags",
				"PhysicsCore",
				"AIModule",
				"GameplayTasks",
				"NavigationSystem",
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				// ... add private dependencies that you statically link with here ...	
				"UMG",
				"Json",
				"JsonUtilities",
				"AnimGraphRuntime",
				"CfCommon",
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}
