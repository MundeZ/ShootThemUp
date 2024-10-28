// Shoot Them Up Game, All Rights


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjecttile.h"
#include "Kismet//GameplayStatics.h"

void ASTULauncherWeapon::StartFire()
{
    MakeShot();
}

void ASTULauncherWeapon::MakeShot()
{
    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    auto ProjectTile = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), ProjecttileClass, SpawnTransform);
    // set params
    UGameplayStatics::FinishSpawningActor(ProjectTile, SpawnTransform);
}