using UnrealBuildTool;

public class BlueprintLibrary : ModuleRules
{
    public BlueprintLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        // 公开依赖 - 使用本模块的其他模块也会得到这些依赖
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine"
        });

        // 私有依赖 - 仅本模块内部使用
        PrivateDependencyModuleNames.AddRange(new string[]
        { 
            "Slate",
            "SlateCore"
        });

        // 允许本模块中的函数被蓝图调用
        PublicDefinitions.Add("WITH_BLUEPRINTLIBRARY=1");
    }
}