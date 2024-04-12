// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TheBall.generated.h"

UCLASS()
class FINAL3DUNREAL_API ATheBall : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool DidSoundPlay;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool DidBallFall;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RollingVolumeMultiplier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* BallMaterial;
	
public:	
	ATheBall();

private:
	void InitializeVariables();
	void InitializeComponents();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
