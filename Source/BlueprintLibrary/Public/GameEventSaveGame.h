// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PSVariant.h"
#include "GameEventSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTLIBRARY_API UGameEventSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
    // 事件列表 - 等效 Cereal 的 vector<unique_ptr<PSVariant>>
    // Instanced 确保子类数据完整保存（相当于 Cereal 的类型注册）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Instanced)
    TArray<UPSVariant*> EventList;
	
};
