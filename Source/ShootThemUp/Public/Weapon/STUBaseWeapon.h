#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ASTUBaseWeapon();
    virtual void StartFire();
    virtual void StopFire();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    FName MuzzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float DamageAmout = 10.0f;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float BulletSpread = 1.5f;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    float TimeBetweenShots = 0.1f;
    
    virtual void BeginPlay() override;

    void MakeShot();
    APlayerController* GetPLayerController() const;
    bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;
    FVector GetMuzzleWorldLocation() const;
    bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
    void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);
    void MakeDamage(const FHitResult& HitResult);
    
private:
    
    FTimerHandle ShotTimerHandle;
};