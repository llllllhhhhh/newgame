// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PSVariant.h"
#include "ShootEvent.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTLIBRARY_API UShootEvent : public UPSVariant
{
	GENERATED_BODY()
public:
    UShootEvent();

    // 伤害值 - 等效 Cereal 的 float damage
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    float Damage;

    // 武器名称 - 等效 Cereal 的 std::string weaponName
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
    FString WeaponName;

    virtual FString GetEventDescription() const override;
};
