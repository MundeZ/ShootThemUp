// Shoot Them Up Game, All Rights


#include "Menu/STUMenuGameModeBase.h"

#include "Menu/STUMenuPlayerController.h"

ASTUMenuGameModeBase::ASTUMenuGameModeBase()
{
    PlayerControllerClass = ASTUMenuPlayerController::StaticClass();
}
