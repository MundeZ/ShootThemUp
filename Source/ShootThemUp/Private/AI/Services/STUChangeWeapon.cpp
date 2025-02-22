// Shoot Them Up Game, All Rights


#include "AI/Services/STUChangeWeapon.h"

#include "AIController.h"
#include "STUUtils.h"
#include "STUWeaponComponent.h"


USTUChangeWeapon::USTUChangeWeapon()
{
    NodeName = TEXT("Change Weapon");
}

void USTUChangeWeapon::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    const auto Controller = OwnerComp.GetAIOwner();
    const auto Blackboard = OwnerComp.GetBlackboardComponent();

    if (Blackboard)
    {
        const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
        if (WeaponComponent && Probability > 0 && FMath::FRand() <= Probability)
        {
            WeaponComponent->NextWeapon();
        }
    }
}