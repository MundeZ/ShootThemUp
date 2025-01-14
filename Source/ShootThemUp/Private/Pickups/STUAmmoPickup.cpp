// Shoot Them Up Game, All Rights


#include "Pickups/STUAmmoPickup.h"
DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    UE_LOG(LogAmmoPickup, Display, TEXT("Giving ammo to %s"), *PlayerPawn->GetName());
    return true;
}