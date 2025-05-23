// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUAmmoDecorator.generated.h"

class ASTUBaseWeapon;
struct FAmmoData;
/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUAmmoDecorator : public UBTDecorator
{
    GENERATED_BODY()

    USTUAmmoDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
    TSubclassOf<ASTUBaseWeapon> WeaponType;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};