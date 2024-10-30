// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjecttile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUProjecttile : public AActor
{
    GENERATED_BODY()

public:
    ASTUProjecttile();
    void SetShotDirection(const FVector& Direction) {ShotDirection = Direction;};
protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    UProjectileMovementComponent* MovementComponent;
    
    virtual void BeginPlay() override;
private:
    FVector ShotDirection;
};