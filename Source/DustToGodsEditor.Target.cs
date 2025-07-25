// Designed by Lu Xiaomi

using UnrealBuildTool;
using System.Collections.Generic;

public class DustToGodsEditorTarget : TargetRules
{
	public DustToGodsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DustToGods" } );
	}
}
