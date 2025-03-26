// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "AI/Decorators/STUAmmoDecorator.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeapon;


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USTUWeaponComponent();

    virtual void StartFire();
    void StopFire();
    virtual void NextWeapon();
    void Reload();

    bool GetWeaponUIData(FWeaponUIData& UIData) const;
    bool GetWeaponAmmoData(FAmmoData& AmmoData) const;

    bool TryToAddAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType, int32 ClipsAmount);
    bool NeedAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType);


protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponData;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    UPROPERTY(EditDefaultsOnly, Category="Weapon")
    UAnimMontage* EquipAnimMontage;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    UPROPERTY()
    ASTUBaseWeapon* CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ASTUBaseWeapon*> Weapons;

    bool CanFire() const;
    bool CanEquip() const;
    
    void EquipWeapon(int32 WeaponIndex);
    int32 CurrentWeaponIndex = 0;
private:
    UPROPERTY()
    UAnimMontage* CurrentReloadAnimMontage = nullptr;
    
    bool EquipAnimInProgress = false;
    bool ReloadAnimInProgress = false;

    void AttachWeaponToSocket(ASTUBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
    void SpawnWeapons();

    void PlayAnimMontage(UAnimMontage* Animation);
    void initAnimations();
    void OnEquipFinished(USkeletalMeshComponent* MeshComponent);
    void OnReloadFinished(USkeletalMeshComponent* MeshComponent);

    bool CanReload() const;
    void OnEmptyClip(ASTUBaseWeapon* AmmoEmptyWeapon);
    void ChangeClip();
};