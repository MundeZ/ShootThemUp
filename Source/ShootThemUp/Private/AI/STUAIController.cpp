// Shoot Them Up Game, All Rights


#include "AI/STUAIController.h"
#include "AI/STUAICharacter.h"
#include "Components/STUAIPerceptionComponent.h"

ASTUAIController::ASTUAIController()
{
    STUAIPerceptationComponent = CreateDefaultSubobject<USTUAIPerceptionComponent>(TEXT("STUPerceptionComponent"));
    SetPerceptionComponent(*STUAIPerceptationComponent);
}


void ASTUAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);
    if (STUCharacter)
    {
        RunBehaviorTree(STUCharacter->BehaviorTreeAsset);
    }
}

void ASTUAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    const auto AimActor = STUAIPerceptationComponent->GetClosesEnemy();
    SetFocus(AimActor);
}