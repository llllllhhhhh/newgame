// Fill out your copyright notice in the Description page of Project Settings.


#include "PSVariant.h"

UPSVariant::UPSVariant()
    : EventId(0)
    , EventName(TEXT("BaseEvent"))
{
}

FString UPSVariant::GetEventDescription() const
{
    return FString::Printf(TEXT("[%d] %s"), EventId, *EventName);
}   