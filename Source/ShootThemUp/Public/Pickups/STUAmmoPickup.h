// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUAmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUAmmoPickup : public ASTUBasePickup
{
    GENERATED_BODY()

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};