// Fill out your copyright notice in the Description page of Project Settings.


#include "UEventSaveSubsystem.h"
#include "GameEventSaveGame.h"
#include "ShootEvent.h"
#include "JumpEvent.h"
#include "HealEvent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"



bool UUEventSaveSubsystem::SaveEvents(const TArray<UPSVariant*>& EventList, const FString& SlotName)
{

    // 创建存档对象 - 等效 Cereal 的 std::ofstream
    UGameEventSaveGame* SaveGameObj = Cast<UGameEventSaveGame>(
        UGameplayStatics::CreateSaveGameObject(UGameEventSaveGame::StaticClass())
    );

    if (!SaveGameObj)
    {
        UE_LOG(LogTemp, Error, TEXT("无法创建存档对象"));
        return false;
    }

    // 复制事件列表 - 等效 Cereal 的 archive(eventList)
    SaveGameObj->EventList = EventList;

    // 保存到文件
    bool bSuccess = UGameplayStatics::SaveGameToSlot(SaveGameObj, SlotName, 0);

    if (bSuccess)
    {
        UE_LOG(LogTemp, Log, TEXT("[保存] 成功序列化 %d 个事件到 Slot: %s"), EventList.Num(), *SlotName);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[保存] 序列化失败"));
    }

    return bSuccess;
}

TArray<UPSVariant*> UUEventSaveSubsystem::LoadEvents(const FString& SlotName)
{
    TArray<UPSVariant*> LoadedEvents;

    // 从文件加载 - 等效 Cereal 的 std::ifstream + BinaryInputArchive
    UGameEventSaveGame* SaveGameObj = Cast<UGameEventSaveGame>(
        UGameplayStatics::LoadGameFromSlot(SlotName, 0)
    );

    if (SaveGameObj)
    {
        // 读取事件列表 - 等效 Cereal 的 archive(loadedList)
        // 此时 UE 已经自动完成了类型识别和对象创建
        LoadedEvents = SaveGameObj->EventList;
        UE_LOG(LogTemp, Log, TEXT("[加载] 成功反序列化 %d 个事件从 Slot: %s"), LoadedEvents.Num(), *SlotName);

        // 打印详细信息
        PrintEventInfo(LoadedEvents);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[加载] 无法读取存档: %s"), *SlotName);
    }

    return LoadedEvents;
}

void UUEventSaveSubsystem::PrintEventInfo(const TArray<UPSVariant*>& EventList)
{
    if (EventList.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("[验证] 事件列表为空"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("========== 事件列表验证 =========="));

    for (int32 i = 0; i < EventList.Num(); ++i)
    {
        UPSVariant* Event = EventList[i];
        if (!Event)
        {
            UE_LOG(LogTemp, Warning, TEXT("[事件 %d] 空指针"), i + 1);
            continue;
        }

        // ============================================
        // 类型识别 - 等效 Cereal 示例中的 dynamic_cast
        // ============================================
        if (UJumpEvent* JumpEvent = Cast<UJumpEvent>(Event))
        {
            UE_LOG(LogTemp, Log, TEXT("[事件 %d] 类型: 跳跃 "), i + 1);
            UE_LOG(LogTemp, Log, TEXT("         高度: %.1fm, 滞空: %.1fs"),
                JumpEvent->Height, JumpEvent->AirTime);
            UE_LOG(LogTemp, Log, TEXT("         基类: [%d] %s"),
                JumpEvent->EventId, *JumpEvent->EventName);
        }
        else if (UShootEvent* ShootEvent = Cast<UShootEvent>(Event))
        {
            UE_LOG(LogTemp, Log, TEXT("[事件 %d] 类型: 射击 "), i + 1);
            UE_LOG(LogTemp, Log, TEXT("         伤害: %.1f, 武器: %s"),
                ShootEvent->Damage, *ShootEvent->WeaponName);
            UE_LOG(LogTemp, Log, TEXT("         基类: [%d] %s"),
                ShootEvent->EventId, *ShootEvent->EventName);
        }
        else if (UHealEvent* HealEvent = Cast<UHealEvent>(Event))
        {
            UE_LOG(LogTemp, Log, TEXT("[事件 %d] 类型: 治疗 "), i + 1);
            UE_LOG(LogTemp, Log, TEXT("         治疗量: %.1f, 目标: %s"),
                HealEvent->HealAmount, *HealEvent->Target);
            UE_LOG(LogTemp, Log, TEXT("         基类: [%d] %s"),
                HealEvent->EventId, *HealEvent->EventName);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("[事件 %d] 未知类型"), i + 1);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("===================================="));
}

void UUEventSaveSubsystem::CleanupEvents(TArray<UPSVariant*>& EventList)
{
    // UE 使用垃圾回收，不需要手动 delete
    // 但可以标记为待销毁，加快 GC 回收
    for (UPSVariant* Event : EventList)
    {
        if (Event && IsValid(Event))
        {
            Event->ConditionalBeginDestroy();
        }
    }
    EventList.Empty();
}

TArray<UPSVariant*> UUEventSaveSubsystem::CreateTestEventList()
{
    TArray<UPSVariant*> EventList;

    // 创建跳跃事件 - 等效 std::make_unique<JumpEvent>()
    UJumpEvent* JumpEvent = NewObject<UJumpEvent>();
    JumpEvent->Height = 2.5f;
    JumpEvent->AirTime = 0.8f;
    EventList.Add(JumpEvent);

    // 创建射击事件 - 等效 std::make_unique<ShootEvent>()
    UShootEvent* ShootEvent = NewObject<UShootEvent>();
    ShootEvent->Damage = 50.0f;
    ShootEvent->WeaponName = TEXT("AK47");
    EventList.Add(ShootEvent);

    // 创建治疗事件 - 等效 std::make_unique<HealEvent>()
    UHealEvent* HealEvent = NewObject<UHealEvent>();
    HealEvent->HealAmount = 30.0f;
    HealEvent->Target = TEXT("Player_01");
    EventList.Add(HealEvent);

    UE_LOG(LogTemp, Log, TEXT("[测试] 创建了 %d 个测试事件"), EventList.Num());
    return EventList;
}
