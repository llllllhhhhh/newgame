// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootEvent.h"

UShootEvent::UShootEvent()
{
    EventId = 2002;
    EventName = TEXT("Shoot");
    Damage = 0.0f;
    WeaponName = TEXT("Unknown");
}

FString UShootEvent::GetEventDescription() const
{
    return FString::Printf(TEXT("[射击] 伤害: %.1f, 武器: %s"), Damage, *WeaponName);
}
