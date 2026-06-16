// Private/BlueprintLibraryModule.cpp
#include "BlueprintLibrary.h"
#include "Modules/ModuleManager.h"

void FBlueprintLibraryModule::StartupModule()
{
    // 模块加载时的初始化代码
    // 例如：注册自定义类型、加载配置等
    UE_LOG(LogTemp, Warning, TEXT("BlueprintLibrary Module Started!"));
}

void FBlueprintLibraryModule::ShutdownModule()
{
    // 模块卸载时的清理代码
    UE_LOG(LogTemp, Warning, TEXT("BlueprintLibrary Module Shutdown!"));
}

// 这行宏是必须的 - 它定义了模块的入口点
IMPLEMENT_MODULE(FBlueprintLibraryModule, BlueprintLibrary)