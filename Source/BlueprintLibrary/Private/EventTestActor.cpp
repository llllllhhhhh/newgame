#include "EventTestActor.h"

AEventTestActor::AEventTestActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AEventTestActor::BeginPlay()
{
    Super::BeginPlay();

    // 获取存档子系统
    SaveSubsystem = GetGameInstance()->GetSubsystem<UUEventSaveSubsystem>();

    // 执行测试
    TestSaveEvents();
    TestLoadEvents();
}

void AEventTestActor::TestSaveEvents()
{
    if (!SaveSubsystem) return;

    // 步骤1: 创建测试数据 - 等效 Cereal 的 eventList.push_back(std::move(jump))
    TArray<UPSVariant*> EventList = SaveSubsystem->CreateTestEventList();

    // 步骤2: 序列化到文件 - 等效 Cereal 的 archive(eventList)
    SaveSubsystem->SaveEvents(EventList, TEXT("GameEvents"));

    // 注意：UObject 由 GC 管理，不需要手动释放
}

void AEventTestActor::TestLoadEvents()
{
    if (!SaveSubsystem) return;

    // 步骤3: 反序列化 - 等效 Cereal 的 archive(loadedList)
    // 此时 UE 自动识别类型并创建正确的子类对象
    TArray<UPSVariant*> LoadedEvents = SaveSubsystem->LoadEvents(TEXT("GameEvents"));

    // 步骤4: 验证数据（PrintEventInfo 内部已经做了类型识别）
    // 等效 Cereal 示例中的 dynamic_cast 验证

    // 步骤5: 清理 - 等效 Cereal 的 unique_ptr 自动释放
    SaveSubsystem->CleanupEvents(LoadedEvents);
}