// Shoot Them Up Game, All Rights


#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"
#include "Perception/AISense_Sight.h"

AActor* USTUAIPerceptionComponent::GetClosesEnemy() const
{
    TArray<AActor*> PerceiveActors;

    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceiveActors);
    if (PerceiveActors.Num() == 0) return  nullptr;

    const auto Controller = Cast<AAIController>(GetOwner());
    if (!Controller) return nullptr;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return nullptr;
    
    float BestDistance = MAX_FLT;

    AActor* BestPawn = nullptr;

    for (const auto PerceiveActor : PerceiveActors)
    {
        const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PerceiveActor);
        if (HealthComponent && !HealthComponent->IsDead())
        {
            const auto CurrentDIstance = (PerceiveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
            if (CurrentDIstance < BestDistance)
            {
                BestDistance = CurrentDIstance;
                BestPawn = PerceiveActor;
            }
        }
    }
    return BestPawn;
}