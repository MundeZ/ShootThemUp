// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "STUProjecttile.h"
#include "Weapon/STUBaseWeapon.h"
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