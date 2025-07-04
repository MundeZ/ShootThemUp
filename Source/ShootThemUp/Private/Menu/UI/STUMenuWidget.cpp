// Shoot Them Up Game, All Rights


#include "Menu/UI/STUMenuWidget.h"

#include "EngineUtils.h"
#include "STUGameInstance.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUMenuWidget, All, All);

void USTUMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &USTUMenuWidget::OnStartGame);
    }
}

void USTUMenuWidget::OnStartGame()
{
    if (!GetWorld()) return;
    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance) return;

    if (STUGameInstance->GetStartupLevelName().IsNone())
    {
        UE_LOG(LogSTUMenuWidget, Error, TEXT("No startup level name set!"));
        return;
    }
    UGameplayStatics::OpenLevel(this, STUGameInstance->GetStartupLevelName());
}