// Shoot Them Up Game, All Rights

using UnrealBuildTool;

public class ShootThemUp : ModuleRules
{
	public ShootThemUp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "PhysicsCore", "Niagara", "AIModule", "GameplayTasks", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] { "ShootThemUp/Public/Components" });

		PublicDefinitions.Add("USE_RTTI=0");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}