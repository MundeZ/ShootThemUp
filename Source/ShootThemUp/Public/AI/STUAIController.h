// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "STUAIController.generated.h"

/**
 * 
 */

class USTUAIPerceptionComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUAIController : public AAIController
{
    GENERATED_BODY()
    ASTUAIController();

protected:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
    USTUAIPerceptionComponent* STUAIPerceptationComponent;
    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaSeconds) override;
};