// Shoot Them Up Game, All Rights


#include "Pickups/STUHealthPickup.h"
DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    UE_LOG(LogHealthPickup, Display, TEXT("Giving health to %s"), *PlayerPawn->GetName());
    return true;
}