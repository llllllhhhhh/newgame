// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEventSaveSubsystem.h"
#include "EventTestActor.generated.h"


class UUEventSaveSubsystem;
UCLASS()
class BLUEPRINTLIBRARY_API AEventTestActor : public AActor
{
	GENERATED_BODY()
	
public:
    AEventTestActor();

protected:
    virtual void BeginPlay() override;

private:
    // 测试保存功能
    void TestSaveEvents();

    // 测试加载功能
    void TestLoadEvents();

    UPROPERTY()
    UUEventSaveSubsystem* SaveSubsystem = nullptr;
};
