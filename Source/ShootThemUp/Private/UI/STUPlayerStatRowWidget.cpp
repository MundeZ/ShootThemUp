// Shoot Them Up Game, All Rights


#include "UI/STUPlayerStatRowWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void USTUPlayerStatRowWidget::SetPlayerName(const FText& text)
{
    if (!PlayerNameTextBlock) return;
    PlayerNameTextBlock->SetText(text);
}

void USTUPlayerStatRowWidget::SetKills(const FText& text)
{
    if (!KillsTextBlock) return;
    KillsTextBlock->SetText(text);
}

void USTUPlayerStatRowWidget::SetDeaths(const FText& text)
{
    if (!DeathsTextBlock) return;
    DeathsTextBlock->SetText(text);
}

void USTUPlayerStatRowWidget::SetTeam(const FText& text)
{
    if (!TeamTextBlock) return;
    TeamTextBlock->SetText(text);
}

void USTUPlayerStatRowWidget::SetPlayerIndicatorImage(bool Visible)
{
    if (!PlayerIndicatorImage) return;
    PlayerIndicatorImage->SetVisibility(Visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}