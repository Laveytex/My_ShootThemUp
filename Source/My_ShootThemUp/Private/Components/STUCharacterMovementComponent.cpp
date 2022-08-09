// Shoot Them Up Game, All Right Reserved


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STBBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ASTBBaseCharacter* Player = Cast<ASTBBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed*RunModifire: MaxSpeed;
}