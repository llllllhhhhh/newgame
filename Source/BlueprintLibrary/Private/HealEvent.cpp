// Fill out your copyright notice in the Description page of Project Settings.


#include "HealEvent.h"

UHealEvent::UHealEvent()
{
    EventId = 3003;
    EventName = TEXT("Heal");
    HealAmount = 0.0f;
    Target = TEXT("Unknown");
}

FString UHealEvent::GetEventDescription() const
{
    return FString::Printf(TEXT("[治疗] 恢复: %.1f, 目标: %s"), HealAmount, *Target);
}
