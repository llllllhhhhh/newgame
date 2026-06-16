// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpEvent.h"

UJumpEvent::UJumpEvent()
{
    // 在构造函数中初始化基类成员 - 等效 Cereal 构造函数中的赋值
    EventId = 1001;
    EventName = TEXT("Jump");

    // 初始化子类成员
    Height = 0.0f;
    AirTime = 0.0f;
}

FString UJumpEvent::GetEventDescription() const
{
    return FString::Printf(TEXT("[跳跃] 高度: %.1fm, 滞空: %.1fs"), Height, AirTime);
}
