// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "STUNextLocationTask.generated.h"


/**
 * @class USTUNextLocationTask
 * @brief Represents a custom behavior tree task node for determining the next location in the Shoot Them Up game.
 *
 * This class inherits from the UBTTaskNode and is used to integrate customizable
 * location-based logic in the AI behavior tree. It allows for dynamically setting up
 * the next target location based on specific game requirements. This task node can configure
 * navigation locations to guide AI-controlled characters in the environment.
 */

UCLASS()
class SHOOTTHEMUP_API USTUNextLocationTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    USTUNextLocationTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float SearchRadius = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector AimLocationKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool SelfCenter = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (EditCondition = "!SelfCenter"))
    FBlackboardKeySelector CenterActorKey;
};