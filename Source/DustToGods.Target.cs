// Designed by Lu Xiaomi

using UnrealBuildTool;
using System.Collections.Generic;

public class DustToGodsTarget : TargetRules
{
	public DustToGodsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DustToGods" } );
	}
}
