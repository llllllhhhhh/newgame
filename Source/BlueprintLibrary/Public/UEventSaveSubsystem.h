// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PSVariant.h"
#include "UEventSaveSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTLIBRARY_API UUEventSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    // 保存事件列表到文件（等效 Cereal 的序列化）
    UFUNCTION(BlueprintCallable, Category = "EventSave")
    bool SaveEvents(const TArray<UPSVariant*>& EventList, const FString& SlotName = TEXT("GameEvents"));

    // 从文件加载事件列表（等效 Cereal 的反序列化）
    UFUNCTION(BlueprintCallable, Category = "EventSave")
    TArray<UPSVariant*> LoadEvents(const FString& SlotName = TEXT("GameEvents"));

    // 打印事件信息（等效 Cereal 示例中的 dynamic_cast 验证）
    UFUNCTION(BlueprintCallable, Category = "EventSave")
    void PrintEventInfo(const TArray<UPSVariant*>& EventList);

    // 清理事件列表（防止内存泄漏）
    UFUNCTION(BlueprintCallable, Category = "EventSave")
    void CleanupEvents(TArray<UPSVariant*>& EventList);

    // 创建测试事件列表
    UFUNCTION(BlueprintCallable, Category = "EventSave")
    TArray<UPSVariant*> CreateTestEventList();
};
