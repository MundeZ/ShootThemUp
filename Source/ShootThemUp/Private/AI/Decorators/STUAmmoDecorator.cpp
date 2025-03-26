// Shoot Them Up Game, All Rights


#include "AI/Decorators/STUAmmoDecorator.h"
#include "AIController.h"
#include "STUUtils.h"
#include "STUWeaponComponent.h"
#include "Weapon/STUBaseWeapon.h"

USTUAmmoDecorator::USTUAmmoDecorator()
{
    NodeName = "Need Ammo";
}

bool USTUAmmoDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;
    
    return WeaponComponent->NeedAmmo(WeaponType);
}