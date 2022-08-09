// Shoot Them Up Game, All Right Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class My_ShootThemUpTarget : TargetRules
{
	public My_ShootThemUpTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "My_ShootThemUp" } );
	}
}
