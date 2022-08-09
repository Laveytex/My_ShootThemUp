// Shoot Them Up Game, All Right Reserved


#include "Player/STBBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/STUCharacterMovementComponent.h"

// Sets default values
ASTBBaseCharacter::ASTBBaseCharacter(const FObjectInitializer&ObjInit):Super(ObjInit.SetDefaultSubobjectClass<USTUCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation=true;
    
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
    
}

// Called when the game starts or when spawned
void ASTBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTBBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTBBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent->BindAxis("MoveForward", this,&ASTBBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this,&ASTBBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this,&ASTBBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this,&ASTBBaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTBBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Run",IE_Pressed,this,&ASTBBaseCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run",IE_Released,this,&ASTBBaseCharacter::OnStopRunning);    
}

void ASTBBaseCharacter::MoveForward(float Amount)
{
    IsMovingForward = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTBBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(),Amount);
}

void ASTBBaseCharacter::OnStartRunning()
{
    WantsToRun = true;
}

void ASTBBaseCharacter::OnStopRunning()
{
    WantsToRun = false;
}

bool ASTBBaseCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

/*void ASTBBaseCharacter::LookUp(float Amount)
{
    AddControllerPitchInput(Amount);
}

void ASTBBaseCharacter::TurnAround(float Amount)
{
    AddControllerYawInput(Amount);
}

*/
