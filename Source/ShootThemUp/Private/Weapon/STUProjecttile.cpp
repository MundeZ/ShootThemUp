// Shoot Them Up Game, All Rights
#include "Weapon/STUProjecttile.h"
#include "Components/SphereComponent.h"

ASTUProjecttile::ASTUProjecttile()
{
    PrimaryActorTick.bCanEverTick = false;
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);
}

void ASTUProjecttile::BeginPlay()
{
    Super::BeginPlay();
}