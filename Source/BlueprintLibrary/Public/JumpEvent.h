// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PSVariant.h"
#include "JumpEvent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew)
class BLUEPRINTLIBRARY_API UJumpEvent : public UPSVariant
{
	GENERATED_BODY()
public:

    UJumpEvent();

    // 跳跃高度 - 等效 Cereal 的 float height
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    float Height;

    // 滞空时间 - 等效 Cereal 的 float airTime
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    float AirTime;

    virtual FString GetEventDescription() const override;
};
