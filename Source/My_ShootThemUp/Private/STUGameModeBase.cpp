// Shoot Them Up Game, All Right Reserved


#include "STUGameModeBase.h"
#include "Player/STBBaseCharacter.h"
#include "Player/STUPlayerController.h"

ASTUGameModeBase::ASTUGameModeBase()
{
         DefaultPawnClass = ASTUGameModeBase:: StaticClass();
         PlayerControllerClass = ASTUGameModeBase::StaticClass();
    
                
}
