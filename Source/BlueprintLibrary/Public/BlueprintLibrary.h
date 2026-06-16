
// Public/BlueprintLibraryModule.h
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

/**
 * BlueprintLibrary 模块的入口接口
 */
class FBlueprintLibraryModule : public IModuleInterface
{
public:
    /** 模块加载时调用 */
    virtual void StartupModule() override;

    /** 模块卸载时调用 */
    virtual void ShutdownModule() override;
};