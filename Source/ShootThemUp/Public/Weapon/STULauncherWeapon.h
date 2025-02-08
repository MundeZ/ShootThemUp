// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include <Weapon/STUProjecttile.h>
#include "STULauncherWeapon.generated.h"


UCLASS()
class SHOOTTHEMUP_API ASTULauncherWeapon : public ASTUBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
    TSubclassOf<ASTUProjecttile> ProjecttileClass;

    virtual void MakeShot() override;

};