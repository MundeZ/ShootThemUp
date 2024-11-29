// Shoot Them Up Game, All Rights


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjecttile.h"


void ASTULauncherWeapon::StartFire()
{
    MakeShot();
}

void ASTULauncherWeapon::MakeShot()
{
    if (!GetWorld() || IsAmmoEmpty())
        return;

    FVector TraceStart, TraceEnd;
    GetTraceData(TraceStart, TraceEnd);

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ASTUProjecttile* ProjectTile = GetWorld()->SpawnActorDeferred<ASTUProjecttile>(ProjecttileClass, SpawnTransform);
    if (ProjectTile)
    {
        ProjectTile->SetShotDirection(Direction);
        ProjectTile->SetOwner(GetOwner());
        ProjectTile->FinishSpawning(SpawnTransform);
    }
    DecreaseAmmo();
}