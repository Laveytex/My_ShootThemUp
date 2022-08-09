// Shoot Them Up Game, All Right Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class My_ShootThemUpEditorTarget : TargetRules
{
	public My_ShootThemUpEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "My_ShootThemUp" } );
	}
}
