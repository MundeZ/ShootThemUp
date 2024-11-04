// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;
    virtual void StopFire() override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float BulletSpread = 1.5f;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    float TimeBetweenShots = 0.1f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float DamageAmout = 10.0f;

    virtual void MakeShot() override;
    virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;
    void MakeDamage(const FHitResult& HitResult);

private:
    FTimerHandle ShotTimerHandle;
};