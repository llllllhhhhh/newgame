// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PSVariant.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, DefaultToInstanced)
class BLUEPRINTLIBRARY_API UPSVariant : public UObject
{
	GENERATED_BODY()

public:
	UPSVariant();
	
    // 事件ID - 等效 Cereal 的 int eventId
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    int32 EventId;

    // 事件名称 - 等效 Cereal 的 std::string eventName
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    FString EventName;

    // 获取事件描述（调试用）
    UFUNCTION(BlueprintCallable, Category = "Event")
    virtual FString GetEventDescription() const;

private:

	
};
