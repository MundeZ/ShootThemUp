// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "STUFireService.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUFireService : public UBTService
{
    GENERATED_BODY()

public:
    USTUFireService();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};