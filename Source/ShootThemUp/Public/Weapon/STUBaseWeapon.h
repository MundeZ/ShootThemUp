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
    virtual void Fire();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    FName MuzzleSocketName = "MuzzleSocket";
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    float TraceMaxDistance = 1500.0f;
    
    virtual void BeginPlay() override;

    void MakeShot();
};