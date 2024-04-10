// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayerBall.generated.h"

UCLASS()
class FINAL3DUNREAL_API AMyPlayerBall : public AActor
{
	GENERATED_BODY()

private:
	bool didSoundPlay;
	bool isBallFalling;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RollingVolumeMultiplier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAudioComponent* RollingBallTest;

public:	
	// Sets default values for this actor's properties
	AMyPlayerBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
