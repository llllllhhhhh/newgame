// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PSVariant.h"
#include "HealEvent.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTLIBRARY_API UHealEvent : public UPSVariant
{
	GENERATED_BODY()
public:
    UHealEvent();

    // 治疗量
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    float HealAmount;

    // 目标对象
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    FString Target;

    virtual FString GetEventDescription() const override;
};
