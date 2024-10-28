// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjecttile.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUProjecttile : public AActor
{
    GENERATED_BODY()

public:
    ASTUProjecttile();

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    USphereComponent* CollisionComponent;

    virtual void BeginPlay() override;
};