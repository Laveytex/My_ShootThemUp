// Shoot Them Up Game, All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "STBBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MY_SHOOTTHEMUP_API ASTBBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTBBaseCharacter(const FObjectInitializer&ObjInit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

        UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
        UCameraComponent* CameraComponent;
        UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
        USpringArmComponent* SpringArmComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category="Movement")
    bool IsRunning() const;
protected:
    bool WantsToRun = false;
    bool IsMovingForward = false;
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    
    void OnStartRunning();
    void OnStopRunning();


};
