// Shoot Them Up Game, All Rights

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "STUHealthComponent.generated.h"

class UCameraShakeBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USTUHealthComponent();

    FOnDeathSignature OnDeath;
    FOnHealthChangedSignature OnHealthChanged;

    float GetHealth() const
    {
        return Health;
    }

    UFUNCTION(BlueprintCallable, Category= "Health")
    bool IsDead() const
    {
        return FMath::IsNearlyZero(Health);
    };

    UFUNCTION(BlueprintCallable, category="Health")
    float GetHealthPercent() const { return Health / MaxHealth; }
    
    bool TryToAddHealth(float HealthAmount);
    bool IsHealthFull() const;
    bool IsHealthZero() const;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(ClampMin="0.0", ClampMax="100.0"))
    float MaxHealth = 100.0f;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal")
    bool AutoHeal = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal", meta=(ClampMin="0.0", ClampMax="1.0", EditCondition="AutoHeal"))
    float HealUpdateTime = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal", meta=(ClampMin="0.0", ClampMax="10.0", EditCondition="AutoHeal"))
    float HealDelay = 3.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Heal", meta=(ClampMin="0.0", ClampMax="10.0", EditCondition="AutoHeal"))
    float HealModifier = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="VFX")
    TSubclassOf<UCameraShakeBase> CameraShake;
    
    virtual void BeginPlay() override;

private:
    FTimerHandle HealTimerHandle;
    float Health = 100.0f;


    UFUNCTION(Category="Health")
    void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy,
                         AActor* DamageCauser);
    void HealUpdate();
    void SetHealth(float NewHealth);

    void PlayCameraShake();

    void Killed(AController* KilledController);
};