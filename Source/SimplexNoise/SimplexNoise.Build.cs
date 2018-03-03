/*
 SimplexNoise 1.0.0
 -----
 DevDad - Afan Olovcic @ www.art-and-code.com - 08/12/2015
*/
using UnrealBuildTool;

public class SimplexNoise : ModuleRules
{
	public SimplexNoise(ReadOnlyTargetRules Target) : base(Target)	//4.16+ Module Constructor
	//public SimplexNoise(TargetInfo Target) //4.15 Module Constructor
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        //Private Paths
        PrivateIncludePaths.AddRange(new string[] { 
			"SimplexNoise/Private"
		});
		
        PublicDependencyModuleNames.AddRange(
			new string[] { 
				"Core", 
				"CoreUObject", 
				"Engine"
			}
		);
	}
}
