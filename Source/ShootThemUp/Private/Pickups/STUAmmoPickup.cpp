// Shoot Them Up Game, All Rights

#include "Pickups/STUAmmoPickup.h"

#include "STUUtils.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
    if (!WeaponComponent) return false;

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}